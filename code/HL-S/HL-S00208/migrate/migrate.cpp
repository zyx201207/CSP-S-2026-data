#include<bits/stdc++.h>
using namespace std;
int a[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=1;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		} 
		for(int i=d;i>0;i--){
			ans*=i;
		}
			cout<<ans/2<<endl;
	}
	return 0;
}
