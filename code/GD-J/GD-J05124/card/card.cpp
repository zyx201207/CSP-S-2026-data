#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],vis[300010],ans[300010];
stack<int> s,l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				s.push(a[j]);
//				cout<<i<<". "<<j<<". ";
//				while(!s.empty()){
//					l.push(s.top());
//					s.pop();
//				}
//				while(!l.empty()){
//					cout<<l.top()<<" ";
//					s.push(l.top());
//					l.pop();
//				}
//				cout<<endl;
			}
			else{
				while(!s.empty()){
					if(s.top()==a[j])break;
					vis[s.top()]=0;
					s.pop();
				}
//				cout<<i<<". "<<j<<". ";
//				while(!s.empty()){
//					l.push(s.top());
//					s.pop();
//				}
//				while(!l.empty()){
//					cout<<l.top()<<" ";
//					s.push(l.top());
//					l.pop();
//				}
//				cout<<endl;
			} 
		}
		while(!s.empty()){
			int e=s.top();
			s.pop();
			ans[e]++;
		}
		memset(vis,0,sizeof(vis));
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
