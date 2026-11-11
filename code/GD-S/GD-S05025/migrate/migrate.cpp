#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T;
ll n=0,d=0;
ll w[5005][5005]={0},x[5005]={0},t[5005][5005]={0};
bool s[5005][5005]={0};
void solve(ll start,ll now,ll step){
	if(w[start][now]>step){
			t[start][now]=1;
			w[start][now]=step;
	}
	else if(w[start][now]==step) t[start][now]++;
	
	if(now==n){
		return ;
	}
	for(ll i=now+1;i<=n;i++){
		if(!s[now][i]) break;
		solve(start,i,step+1);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){ 
		n=0;
		d=0;
		memset(w,0x3f3f3f3f,sizeof(w));
		memset(x,0,sizeof(x));
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		cin>>n>>d;
		if(n>5000){
			cout<<1<<endl;
			continue;
		}
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])>d) break;
				s[i][j]=1;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<s[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		int ans=0;
		for(ll i=1;i<=n;i++) solve(i,i,0);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(t[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
