#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,m,a[N],L[N],R[N],pre[N],suf[N],ans;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=suf[i]=0;
	}
	L[1]=1;
	for(int i=2;i<=n;i++)
	{
		L[i]=L[i-1];
		while(a[i]-a[L[i]]>m)L[i]++;
	}
	L[0]=R[0]=0;
	R[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		R[i]=R[i+1];
		while(a[R[i]]-a[i]>m)R[i]--;
	}
	L[n+1]=R[n+1]=n+1;
	for(int i=1;i<=n;i++){
		if(R[i]!=i&&L[R[i]]!=i)pre[R[i]]++;
		if(L[i]!=i&&R[L[i]]!=i)suf[L[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]++;
		if(L[i]!=i&&R[L[i]]==i)pre[i]+=pre[L[i]];
	}
	for(int i=n;i>=1;i--)
	{
		suf[i]++;
		if(R[i]!=i&&L[R[i]]==i)suf[i]+=suf[R[i]];
	}
	ans=0;
	for(int i=2;i<n-1;i++)
	{
		if(R[i]<=i+1||L[i+1]>=i)continue;
		int lv=max(0ll,min(L[i+2],i-1)-L[i+1]),rv=max(0ll,R[i]-max(R[i-1],i+2));
		if(L[i]!=i-1&&R[i+1]!=i+2&&L[i]==L[i+1]&&R[i]==R[i+1]&&L[i+2]!=L[i]&&R[i-1]!=R[i]){
			lv+=pre[L[i]]-1;
			rv+=suf[R[i]]-1;
		}
		ans+=lv*rv;
		if(R[i-1]==i+1){
			lv=((L[i]==i-1&&L[i+1]==i-1)?pre[i-1]:1);
			rv=R[i]-i-1;
			if(R[i]==R[i+1])rv+=suf[R[i]]-1;
			ans+=lv*rv;
		}
		if(L[i+2]==i){
			rv=((R[i]==i+2&&R[i+1]==i+2)?suf[i+2]:1);
			lv=i-L[i+1];
			if(L[i]==L[i+1])lv+=pre[L[i]]-1;
			ans+=lv*rv;
		}
		if(L[i+2]==i&&R[i-1]==i+1){
			ans-=((R[i]==i+2&&R[i+1]==i+2)?suf[i+2]:1)*((L[i]==i-1&&L[i+1]==i-1)?pre[i-1]:1);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--)solve();
	return 0;
}
