#include<bits/stdc++.h>
using namespace std;
int n,m,ls[500005];
queue<int>a;
vector<int>q;
int ans[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ls[i];
		a.push(ls[i]);
	}
	for(int i=1;i<=n;i++){
		bool vis[300005];
		for(int j=1;j<=i-1;j++){
			a.push(a.front() );
			a.pop();
		}
		for(int j=i;j<=n;j++){
			q.push_back(a.front());
			a.push(a.front() );
			a.pop();
		}
		for(int j=1;j<=q.size();j++){
			if(vis[q[j]]){
				int flag=0;
				for(int k=j-1;j>=1;k--){
					if(q[k]==q[j]){
						flag=k;
					}
				}
				for(int k=1;k<=q.size()-flag;k++){
					q[i]=q[i+flag];
				}
				memset(vis,0,sizeof(vis) );
				for(int k=1;k<=j;k++){
					vis[q[k]]=1;
				}
			}else{
				vis[q[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

