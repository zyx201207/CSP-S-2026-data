#include<bits/stdc++.h>
using namespace std;
vector<int> g[300010];
int a[500010],n,m,cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	for(int st=1;st<=n;st++){
		int i=st;
		while(i<=n){
			cnt[a[i]]++;
			if(g[a[i]].size()==1) i++;
			else i=g[a[i]][g[a[i]].size()-1]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
