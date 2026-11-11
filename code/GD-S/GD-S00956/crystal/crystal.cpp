#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep1(i,s,t) for(int i=s;i>t;i--)
#define set(ai,k) memset(ai,k,sizeof(ai))
#define srt(ai,n) sort(ai+1,ai+1+n)
#define csrt(ai,n,cmp) sort(ai+1,ai+1+n,cmp)
#define pb push_back
using namespace std;
const int N=5e5+5;
int n,ai[N],m,t,ans=1,sm[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;sm[0]=0;
	rep(i,1,n)cin>>ai[i];srt(ai,n);
	rep(i,1,n)sm[i]=sm[i-1]+ai[i];
	t=1;
	rep(i,2,n){
		while(t<i&&ai[i]*(i-t+1)-(sm[i]-sm[t-1])>m)t++;
		ans=max(ans,i-t+1);
	//	if(i-t+1==4236)cout<<i<<" "<<t<<' '<<ai[i]<<" "<<sm[i]<<' '<<sm[t-1]<<" "<<m<<endl;
	}cout<<ans<<endl;
}
