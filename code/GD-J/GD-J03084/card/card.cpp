#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[300005];
ll s[300005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		stack<ll>p;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				p.push(a[j]);
				vis[a[j]]=true;
			}else{
				int k=j-1;
				while(!p.empty()){
					if(p.top()==a[j])break;
					p.pop();
					vis[a[k--]]=false;
				}
			}
		}
		while(!p.empty()){
			s[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
} 
