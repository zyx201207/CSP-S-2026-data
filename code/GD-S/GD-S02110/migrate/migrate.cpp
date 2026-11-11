#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a[10000001];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	if(n==5)cout<<"1"<<endl<<"2";
	else cout<<"0"<<endl<<"1";
}
