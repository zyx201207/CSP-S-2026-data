#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
struct Node{
	int at;
	int cnt;
};
queue<Node>bfs;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		int u,v;
		int ans=0;
		int sum=INT_MAX,islands=0;
		for(int i=0;i<n;i++){
			if(x[i+1]-x[i]>d) continue;
			for(int j=i+1;j<n;j++){
				if(x[j]-x[j-1]>d)break;
				if(j<i+3)continue;
				v=j;
			}
			Node s;
			s.at=i;
			s.cnt=0;
			bfs.push(s);
			while(!bfs.empty()){
				Node h=bfs.front();
				if(h.at==v&&h.cnt<=sum){
					if(h.cnt<sum){
						islands=0;
						islands++;
					}
					islands++;
				}
				for(int j=h.at+1;j<=n;j++){
					if(x[j]-x[h.at]>d) break;
					Node t;
					t.at=j;
					t.cnt=h.cnt+1;
				}
			}
			if(islands==2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
