#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		for(int ii=0;ii<t;ii++){
			int n;
			cin>>n;
			int a[n+1];
			for(int i=0;i<=n;i++){
				cin>>a[i];
			}
			if(a[n]-a[1]<=a[0]){
				cout<<0<<endl;
			}else{
				cout<<n-3<<endl;
			}
		}
	}else{
		for(int ii=0;ii<t;ii++){
			int n;
			cin>>n;
			int a[n+1];
			for(int i=0;i<=n;i++){
				cin>>a[i];
			}
			if(a[n]-a[1]<=a[0]){
				cout<<0<<endl;
			}else{
				cout<<n-3<<endl;
			}
		}
	}
	return 0;
} 
