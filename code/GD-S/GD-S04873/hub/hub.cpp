#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int x,y;
	for(int i=1;i<=t;i++){
		int n,m;
		cin>>n>>m;
		
		for(int j=1;j<=n-1;j++){
			cin>>x>>y;
		}
		cout<<m<<endl;
	}
	return 0;
}
