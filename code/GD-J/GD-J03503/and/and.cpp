#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,m;
stack<ll> q;
struct{
	ll a=0,one=0,zero=0;
}b[N];
bool vis[N];
ll MAX_P;
void dfs(ll ans,ll cur){
	if(cur==m+1) {
		MAX_P=max(MAX_P,ans);
		while(!q.empty()){
			cout<<q.top()<<" ";
			q.pop();
		}
		cout<<endl;
		return;
	}else{
		for(ll i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				q.push(b[i].a);
				if(cur==1) dfs(b[cur].a,cur+1);
				else dfs(ans&b[cur].a,cur+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll maxa=-1,ans;bool apha=1;
	for(ll i=1;i<=n;i++) {
		cin>>b[i].a;
		for(ll i=1;i<=20;i++) if((1<<i)-1!=b[i].a) apha=0; 
		maxa=max(maxa,b[i].a);
		if(i==1) ans=b[i].a;
		else ans=ans&b[i].a;
	}
	if(m==1||apha==1) cout<<maxa;
	else if(m==n) cout<<ans; 
	else dfs(b[0].a,1);
	cout<<MAX_P;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
