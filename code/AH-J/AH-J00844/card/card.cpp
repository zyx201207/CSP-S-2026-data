#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,a[N],vis[N],id[N];
stack<int>s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		//cout<<endl<<endl<<"di"<<j<<"ju:"<<endl;
		memset(vis,0,sizeof(vis));
		for(int i=j;i<=n;i++){
			if(vis[a[i]]==0){
				s.push(a[i]);
				vis[a[i]]++;
				//cout<<"dangqian: "<<a[i]<<' '<<vis[a[i]]<<endl;
			}else if(vis[a[i]]!=0){
				while((!s.empty())&&s.top()!=a[i]){
					//cout<<"shouzou: "<<s.top()<<endl;
					vis[s.top()]--; 
					s.pop();
				}
			}
		}
		while(!s.empty()){
			id[s.top()]++;
			//cout<<"shenyu: "<<s.top()<<' '<<id[s.top()]<<' ';
			s.pop();
		}
	}
	//cout<<endl;
	for(int i=1;i<=m;i++)cout<<id[i]<<' ';
	return 0;
}
