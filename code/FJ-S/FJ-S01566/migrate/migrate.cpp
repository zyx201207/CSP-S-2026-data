#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define st first
#define nd second
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int N=5010;
int c,t,n,ans,f[N][N];
ll d,x[N],cnt[N][N];
bool check1(int l,int r,int p){
	return p==(f[l][r]-1);
}
bool check2(int l,int r,int p){
	return p==(f[l][r]-1)*2;
}
void solve(){
	ans=0,mem(f,0x3f),mem(cnt,0),cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
//			cerr<<l<<' '<<r<<' ';
			if(x[r]-x[l]<=d){
				f[l][r]=1,cnt[l][r]=1;
//				cerr<<f[l][r]<<' '<<cnt[l][r]<<endl;
				continue;
			}
			int flag=0,lc;
			for(int i=l+1;i<=r-1;i++){
				int dis=f[l][i]+f[i][r];
				if(dis>f[l][r])continue;
				if(dis<f[l][r])f[l][r]=dis,cnt[l][r]=0,flag=0;
				cnt[l][r]++;
				if(cnt[l][i]==2||cnt[i][r]==2){
					if(!flag)flag=i,lc=cnt[l][r]-1;
					else flag=-1;
				}
			}
			if(check2(l,r,cnt[l][r])||(flag>0&&(((check1(l,flag,lc)&&cnt[flag][r]==2))||(check1(flag,r,cnt[l][r]-lc-1)&&cnt[l][flag]==2))))ans++,cnt[l][r]=2;
			else cnt[l][r]=min(cnt[l][r],3);
//			cerr<<f[l][r]<<' '<<cnt[l][r]<<endl;
		} 
	}
	cout<<ans<<endl;
}
signed main(){
	FILE("migrate"),
	ios::sync_with_stdio(false),
	cin.tie(0),cout.tie(0);
	for(cin>>c>>t;t--;solve());
	return 0;
}
