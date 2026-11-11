#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=5e5+10;
const ll maxx=3e5+10;
ll a[maxn],n,m,b[maxx],c[maxx];
queue<ll> q,q1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(ll j=i;j<=n;j++){
			bool sb=0;
			if(c[a[j]]){
				while(!q.empty()){
					if(q.front()!=a[j]&&!sb){
						q1.push(q.front());
						q.pop();
					}
					else{
						sb=1;
						q.pop();
					}
				}
				while(!q1.empty()){
					q.push(q1.front());
					q1.pop();
				}
			}
			q.push(a[j]);
			c[a[j]]++;
		}
		while(!q.empty()){
			b[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

