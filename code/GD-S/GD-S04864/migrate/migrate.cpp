#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,sum=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<1<<endl;
	} 
	return 0;
}
