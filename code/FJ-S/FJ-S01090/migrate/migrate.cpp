#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,T,ans;
long long a[N],d,c[N],l[N];
void bfs(int s){
	queue<int> q;
	q.push(s);
	for(int i=s;i<=n;i++) c[i]=0;
	c[s]=1,l[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(c[u]==2) ans++;
		for(int i=u+1;i<=n;i++){
			if(a[i]-a[u]<=d){
				if(!c[i]){
					l[i]=l[u]+1;
					q.push(i);
				}
				if(l[u]+1==l[i]) c[i]+=c[u];
			}
			else break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
