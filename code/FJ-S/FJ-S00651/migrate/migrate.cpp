#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,l[2000024];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			cin>>l[i];
		}
		cout<<a/b<<endl;
	}
}
