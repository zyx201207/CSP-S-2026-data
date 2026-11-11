#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050],p[300050],ans[300050];
vector<int>v[500050];
bool vis[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}

