#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
namespace yyh{
	int n,d,a[2000005],lg[2000005],cnt[2000005],f[2000005][24],g[2000005][24],sub;
	int get(int l,int r){
		int k=lg[r-l+1];
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
	int get1(int l,int r){
		int k=lg[r-l+1];
		int ans=0,len=r-l+1,t=get(l,r);
		for(int i=k;i>=0;i--)
			if(len&(1<<i))ans+=g[l][i]*(f[l][i]==t),l+=(1<<i);
		return ans;
	}
	int r[2000005];
	void solve(){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<0<<endl;
			return;
		}
		a[n+1]=1e18+10;
		for(int i=1;i<=n;i++)r[i]=upper_bound(a+i+1,a+n+2,a[i]+d)-a-1;
		if(sub<=10){
			int ans=0;
			for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=lg[n];j++)for(int k=1;k+(1<<j)-1<=n;k++)f[k][j]=g[k][j]=0;
				f[i][0]=0;
				g[i][0]=1;
				for(int j=i-1;j>=1;j--){
					if(a[j+1]-a[j]>d)break;
					int d=get(j+1,min(i,r[j]))+1,t=get1(j+1,min(i,r[j]));
					if(t==2)ans++;
					f[j][0]=d;
					g[j][0]=t;
					for(int k=1;k<=lg[n]&&j+(1<<k)-1<=i;k++){
						f[j][k]=min(f[j][k-1],f[j+(1<<(k-1))][k-1]);
						g[j][k]=(f[j][k-1]==f[j][k])*g[j][k-1]+(f[j+(1<<(k-1))][k-1]==f[j][k])*g[j+(1<<(k-1))][k-1];
					}
				}
			}
			cout<<ans<<endl;
			return;
		}
	}
	signed main(){
		int t;
		cin>>sub>>t;
		while(t--)solve();
		return 0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	yyh::main();
	cerr<<"Time: "<<(double)clock()<<"ms";
	return 0;
}
/*
g++ -std=c++14 -O2 -Wl,-stack=100000000 migrate.cpp -o migrate.exe
migrate.exe < migrate1.in > a.out
fc a.out migrate1.ans
migrate.exe < migrate2.in > a.out
fc a.out migrate2.ans
migrate.exe < migrate3.in > a.out
fc a.out migrate3.ans
migrate.exe < migrate4.in > a.out
fc a.out migrate4.ans
migrate.exe < migrate5.in > a.out
fc a.out migrate5.ans
migrate.exe < migrate6.in > a.out
fc a.out migrate6.ans

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
