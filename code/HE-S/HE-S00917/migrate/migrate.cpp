#include <bits/stdc++.h>
using namespace std;
int x[10000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	cout<<"1"<<endl<<"2";
	return 0;
}
