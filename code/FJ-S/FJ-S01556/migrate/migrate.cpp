#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t;
ll n,d,s;
ll a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n-3;i++){
			if(
			a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d
			&&
			a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d
			&&
			a[i+3]-a[i]>d)
//			cout<<a[i]<<' ';
			s++;
		}
		cout<<s<<'\n';
//	cout<<'\n';
	}
}
