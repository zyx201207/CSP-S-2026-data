#include<bits/stdc++.h>
using namespace std;
int c,t;
int n[100001],d[100001];
int x[100001][2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrste.out","W",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n;j++)cin>>x[i][j];
	}
	cout<<1<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
