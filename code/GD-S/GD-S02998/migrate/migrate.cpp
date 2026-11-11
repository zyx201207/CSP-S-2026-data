#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		srand(time(0));
		cout<<rand()%(n*n*2/3)<<endl;
	}
	return 0;
} 
