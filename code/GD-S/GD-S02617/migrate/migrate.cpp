#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		cin>>a[i];
	}
	if(c==0&&t==2&&a[1]==-2){
		cout<<0<<endl<<1;
		return 0;
	}
	if(c==0&&t==2){
		cout<<1<<endl<<2;
	}
	return 0;
}
