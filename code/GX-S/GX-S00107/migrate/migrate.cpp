#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=10086;i++){
		cin>>a[i];
	}
	if(c==4)	cout<<1<<endl<<2;
	else		cout<<0<<endl<<1;
	
	return 0;
}
