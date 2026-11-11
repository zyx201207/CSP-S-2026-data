#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=200003;

ll read(){
	ll x=0,f=1,ch=getchar();
	if(ch<48||ch>57){
		if(ch==45){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int C,T,n,dp[maxn];

ll D,a[maxn],f[maxn],ans,s[maxn];

deque<int>q;

void solve(){
	for(int aoao=1;aoao<=n;aoao++){
		for(int i=1;i<=n;i++){
			s[i]=0;
		}
		while(!q.empty()){
			q.pop_back();
		}
		dp[aoao]=0,f[aoao]=1;
		q.push_back(aoao);
		s[0]=1;
		for(int i=aoao+1;i<=n;i++){
			while((!q.empty())&&a[i]-a[q.front()]>D){
				s[dp[q.front()]]-=f[q.front()];
				q.pop_front();
			}
			if(q.empty()){
				dp[i]=0x3f3f3f3f;
				f[i]=0;
			}else{
				dp[i]=dp[q.front()]+1;
				f[i]=s[dp[q.front()]];
				q.push_back(i);
				s[dp[i]]+=f[i];
			}
			ans+=(f[i]==2);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),D=read(),ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		solve();
	}
	return 0;
}
