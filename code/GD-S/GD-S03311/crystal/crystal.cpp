#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i+1]-a[i];
	}
	int l=1,ans=1;
	a[0]=a[1];
	long long cnt=0;
	for(int i=2;i<=n;i++){
		cnt+=d[i-1]*(i-l);
		while(cnt>m&&l<=i){
			cnt-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
} 
