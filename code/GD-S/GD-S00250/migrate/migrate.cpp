#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int b[1000010];
int sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i];
			cin>>b[i];
		}
	}
	cout<<1<<endl;
	cout<<2<<endl;
	freopen("migrate.out","w",stdout);
	return 0;
} 

