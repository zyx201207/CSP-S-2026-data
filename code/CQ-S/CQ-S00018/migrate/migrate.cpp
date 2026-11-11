#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=2e6+10;
int c,t;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
	 ll n,d;
	 int flag=0;
	 cin>>n>>d;
	 for(int i=1;i<=n;i++){
		cin>>x[i];
	}	
	for(int i=2;i<n;i++){
		if(x[i-1]-x[i]==x[i+1]-x[i])flag=1;
	}
	if(flag==1){
		if(n%2==0){
			cout<<n/2<<"\n";
			continue;
		}else{
			cout<<0<<"\n";
			continue;
		}
	}
	cout<<0<<"\n";
	} 
	return 0;
}
