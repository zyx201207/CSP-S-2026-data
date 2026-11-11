#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		long long ans=1e15+10;
		cin>>n>>k;
		vector<int> t[n+10];
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			t[a].push_back(b);
			t[b].push_back(a);
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				bool book[100010];
				memset(book,0,sizeof(book));
				long long ass=0,cnt=2;
				queue<int> qu,que;
				qu.push(i);
				qu.push(j);
				while(cnt<k){
					while(!qu.empty()){
						int f=qu.front();
						qu.pop();
						for(auto z:t[f]) if(book[z]==0) que.push(z),book[z]=1;
					}while(!que.empty()){
						cnt++;
						qu.push(que.front());
						que.pop();
					}ass++;
				}ans=min(ans,ass);
			}
		}cout<<ans<<'\n';
	}return 0;
}
