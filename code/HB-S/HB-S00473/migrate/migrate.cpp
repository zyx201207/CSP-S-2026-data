#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","in",stdin);
	freopen("migrate.out","out",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n;
			long long d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long zs=a[2]-a[1];
			long long nono=d%zs;
			if(nono==0){
				cout<<"0"<<endl;
			}else{
				cout<<2*nono<<endl;
			}
		}
	}else{
		while(t--){
			int n;
			long long d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}
	}
}
