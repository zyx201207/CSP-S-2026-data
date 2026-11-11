#include<bits/stdc++.h>
using namespace std;
long long a[200010],vis[200010],ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> s;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(s[s.size()-1]!=a[j]){
					vis[s[s.size()-1]]=0;
					if(s.empty()) break;
					s.pop_back();
				}
			}else{
				s.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int i=0;i<s.size();i++){
			ans[s[i]]++;
		}
		while(!s.empty()){
			s.pop_back();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
