#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n,c,ans=1,a[N];
ll m,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	c=0,s=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&1LL*c*a[i]-s>m) s-=a[j],c--,j++;
		ans=max(ans,i-j+1);
		s+=a[i],c++;
	}
	printf("%d\n",ans);
	return 0;
}
