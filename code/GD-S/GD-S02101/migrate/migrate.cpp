#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=2e6+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1;
int n,l[N],r[N];
ll d,x[N],cnt[N],dp[N];
void Case1(){
	int res=0;
	for(int u=1;u<=n;u++){
		cnt[u]=dp[u]=1;
		for(int i=u+1;i<=n;i++) dp[i]=0,cnt[i]=1e15;
		for(int i=u;i<=n;i++){
			for(int j=i+1;j<=r[i];j++){
				if(cnt[j]>cnt[i]+1) dp[j]=0,cnt[j]=cnt[i]+1;
				if(cnt[j]==cnt[i]+1) dp[j]+=dp[i];
			}
		}
		for(int i=u;i<=n;i++) res+=dp[i]==2;
	}
	cout<<res<<"\n";
}
void CaseA(){
	ll res=0;
	for(int i=1;i<=n;i++){
		if(r[i]-i<2) continue;
		int p=r[i]-1,q=r[i]-2;
		res+=(r[p]-max(p,r[q]));
	}
	cout<<res<<"\n";
}
void mian(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int p=1,i=1;i<=n;i++)
		{while(p<=i&&x[i]-x[p]>d) ++p; l[i]=p;}
	for(int p=n,i=n;i;i--)
		{while(i<=p&&x[p]-x[i]>d) --p; r[i]=p;}
	if(C==11||C==12) return CaseA();
	if(C==13||C==14) return cout<<"0\n",void();
	return Case1();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>T; while(T--) mian();
	return 0;
}

