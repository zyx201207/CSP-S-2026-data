#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<int>s;
bool vis[300005];
int a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!s.empty()){
					if(s.top()==a[j]){
						break;
					}
					s.pop();
				}
			}else{
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!s.empty()){
			ans[s.top()]++; 
			s.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

