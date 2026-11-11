#include<bits/stdc++.h>
using namespace std;
long long m,n,ans,cnt;
const int N=5*1e5+100;
long long a[N],b[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[++cnt]=a[i]-a[i-1];	
	}
	for(int i=1;i<=cnt-1;i++){
		if((m-i*b[i])>=0){
			ans=i+1;
			m-=i*b[i];
		}
		else{
			break;	
		}
	}
	printf("%lld",ans);
	return 0;
} 
