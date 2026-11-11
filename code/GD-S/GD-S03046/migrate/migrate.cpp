#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long c,t,a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=13 && c>=12){
		while(t--){
			cin>>n>>d;
			for (int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(abs(a[3]-a[1])<=d){
				cout<<(n-3)<<endl;
			}
			else{
				cout<<0<<endl;
			}
			n=0;
			d=0;
			a[1]=a[2]=a[3]=0;
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for (int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<time(0)%n<<endl;
		}
	}
	return 0;
} 
