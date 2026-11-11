#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,k,b[500005];
bool vis[300005];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int ni=1;ni<=n;ni++){
		memset(vis,0,sizeof(vis));
		for(int i=ni;i<=n;i++){
			if(vis[a[i]]!=0){
				int j=v.size()-1;
				while(v[j]!=a[i]){
					v.pop_back();
					j--;
				}
			}else{
				v.push_back(a[i]);
				vis[a[i]]=1;
			}
		}
		for(int i=0;i<v.size();i++){
			b[v[i]]++;
		}
		while(!v.empty()){
			v.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
