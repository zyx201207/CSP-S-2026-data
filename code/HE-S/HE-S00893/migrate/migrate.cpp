#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
string a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			if(a.size()<4){
				cout<<"0";
			}else if(a.size()==4){
				cout<<"1";
			}else{
				cout<<"2";
			}
		}
	}
	return 0;
}
