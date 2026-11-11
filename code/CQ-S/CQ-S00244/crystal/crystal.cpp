#include<bits/stdc++.h>
using namespace std;
namespace MYQ{
	const int N=500005;
	int n,ans;
	long long m,a[N],s[N];
	inline bool ck(int l,int r){
		long long hx=a[r]*(r-l+1)-(s[r]-s[l-1]);
		if(hx<=m)
			return 1;
		return 0;
	}
	int main(){
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(int l=1,r=1;l<=n;l++){
			while(r<=n&&ck(l,r)==1)
				r++;
			ans=max(ans,r-l);
		}
		printf("%d",ans);
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	MYQ::main();
	return 0;
}
