#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],v[5005],st[5005],ans;
void bfs(int x){
	queue<pair<int,int>> q;
	while(q.size()){
		q.pop();
	}
	for(int i=x;i<=n;i++){
		v[i]=0;
	}
	v[x]=1;
	q.push({x,0});
	while(!q.empty()){
		auto cnt=q.front();
		q.pop();
		for(int i=cnt.first+1;i<=n;i++){
			if(a[i]-a[cnt.first]>m){
				break;
			}
			if(!v[i]){
				st[i]=cnt.second+1;
				v[i]=1;
				q.push({i,cnt.second+1});
			}
			else{
				if(st[i]==cnt.second+1){
					v[i]++;
					q.push({i,cnt.second+1});
				}
			}	
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(v[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

