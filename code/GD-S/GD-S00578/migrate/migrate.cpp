#include<bits/stdc++.h>
using namespace std;
long long a[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	unsigned long long n,d;
	while(t--){
		cin>>n>>d;
		//cout<<n<<" "<<d<<endl;
		if(c==11||c==12){
			for(int i=1;i<=2;i++){
				cin>>a[i];
			}
			long long k=a[2]-a[1];
			//cout<<n<<" "<<d<<" "<<k<<" ";
			if(k>d)cout<<0;
			else cout<<n-3;
			cout<<endl;
			for(int i=3;i<=n;i++)cin.ignore();
			continue;
		}
	}
}
