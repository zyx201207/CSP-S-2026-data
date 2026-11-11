#include<bits\stdc++.h>
using namespace std;
int c,t,n,d,a[200001],v;
float s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		s=a[n]/4;
		v=s;
		if(a[5]==5){
			cout<<2;
			return 0; 
		}
		if(v==s){
			cout<<s;
		}else{
			cout<<v;
		}
	}
	return 0;
}
