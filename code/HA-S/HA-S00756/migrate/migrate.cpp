#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
		for(int p=1;p<=t;p++){
			long long n,d;
			cin>>n>>d;
			//cout<<n<<" "<<d<<endl;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[2]-a[1]>=d)cout<<0<<endl;
			else if(n-2*d/(a[2]-a[1])+1<0)cout<<0<<endl;
			else cout<<n-2*d/(a[2]-a[1])+1<<endl;
		}
	
	return 0;
}
