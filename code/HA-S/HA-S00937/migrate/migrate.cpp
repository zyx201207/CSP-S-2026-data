#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q,w;
	for(int i=1;i<=m;i++){
		int a[10010];
		cin>>q>>w;
		for(int j=1;j<=q;j++){
			cin>>a[i];
		}
		cout<<q/w<<"\n";
	}
	return 0;
}
