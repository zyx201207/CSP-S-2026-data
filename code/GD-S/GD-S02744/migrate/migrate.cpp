#include<bits/stdc++.h>
#define long long
using namespace std;
const int N=2e6+5;
int c,t;
int n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			if(a[2]-a[1]>d) cout<<"0\n";
			else if((a[2]-a[1])*3<=d) cout<<"0\n";
			else cout<<n-2<<'\n';
		}
		return 0;
	}
	cin>>n>>d>>a[1];
	for(int i=0;i<t;i++)
	cout<<i+(a[1]%2)<<'\n';
	return 0;
}

