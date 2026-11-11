#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int x[N];
bool vis[N];
int ret;
vector<int> v[N];
bool bfs(int s,int tar){
	memset(vis,0,sizeof vis);
	int ans=0;
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
//		cout<<"q:";
//		queue<int> q1;
//		while(!q.empty()){
//			q1.push(q.front());
//			cout<<q.front()<<" ";
//			q.pop();
//		}
//		while(!q1.empty()){
//			q.push(q1.front());
//			q1.pop();
//		}
//		cout<<endl;
		int cur=q.front();
		vis[cur]=true;
		q.pop();
//		cout<<"cur:"<<cur<<" tar:"<<tar<<endl;
		if(cur==tar){
			ans++;
//			cout<<"found:"<<tar<<endl;
			while(!q.empty()){
				if(q.front()==tar) ans++/*,cout<<"Found "*/;
//				cout<<"Start:"<<s<<" Tar:"<<tar<<" q.front():"<<q.front()<<" ans:"<<ans<<endl;
				q.pop();
			}
			break;
		}
		for(auto c:v[cur]){
			if(vis[c]) continue;
			q.push(c);
//			cout<<c<<endl;
		}
	}
//	cout<<"end"<<endl<<endl;
	if(ans==2) return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ret=0;
		cin>>n>>d;
		memset(v,0,sizeof v);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<"i="<<i<<": ";
//			for(auto r:v[i]){
//				cout<<r<<" ";
//			}cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(bfs(i,j)) ret++;
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}


/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/