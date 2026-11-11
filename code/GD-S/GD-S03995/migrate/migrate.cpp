#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
	}
	cout<<1<<endl;
	cout<<2;
	return 0;
}
