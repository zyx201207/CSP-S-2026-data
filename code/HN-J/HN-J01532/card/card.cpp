#include<bits/stdc++.h>
using namespace std;
const int xy=222222;
int n,m,u[xy],c[xy];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>u[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=v.size()-1;k>=0;k--)if(v[k]==u[j])v.erase(v.begin()+k,v.end());
			v.push_back(u[j]);
		}
		for(int j=0;j<v.size();j++)c[v[j]]++;
		v.clear();
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
