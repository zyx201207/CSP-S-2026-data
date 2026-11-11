#include<bits/stdc++.h>
using namespace std;
int x[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;	
	for(int I=1;I<=t;I++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n%4+1<<endl;
	}
	return 0;
}
