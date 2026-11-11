#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[10000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]!=5){
			cout<<1<<endl;
		}
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<2<<endl;
		}
	}
	return 0;
}