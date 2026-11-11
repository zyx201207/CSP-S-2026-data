#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e6+10;
int c,t;
int n,d;
ll a[N];
int last[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int flag;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)flag=a[i]-a[i-1];
			if(i>2&&flag!=a[i]-a[i-1])flag=0;
		}
		if(flag>0){
			int leap=d/flag;
			cout<<n-leap*2+1<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
