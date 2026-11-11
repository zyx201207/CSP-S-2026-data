#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],r,ans;
void bfs(int u,int v){
	queue<pair<int,int>>q;
	q.emplace(u,0);
	while(!q.empty()){
		pair<int,int>p=q.front();
		q.pop();
		int a=p.first,b=p.second;
		if(a==v){
			int cnt=0;
			
			while(!q.empty()){
				q.pop();
				cnt++;
			}
			if(cnt==2){
				ans++;
			}
			return ;
		}
		for(int i=a+1;i<=v;i++){
			if(x[i]-x[a]<=d){
				q.emplace(i,b+1);
			}
			else{
				break;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		int flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		r=x[2]-x[1];
		for(int i=1;i<n;i++){
			if(r!=x[i+1]-x[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			d/=r;
			if(d<=1){
				cout<<0<<'\n';
			}
			else{
				cout<<max(n-(d+d-1),0ll)<<'\n';
			}
		}
		else{
			ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					bfs(i,j);
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
