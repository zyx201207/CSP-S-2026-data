//luogu yuanshen
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t,n,d,x[N]; 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("D:\\down\\migrate\\migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}ll num=x[2]-x[1];
		if(num*2>d){
			cout<<"0\n";
			continue;
		}
		ll mk=2*d/num-1;
		cout<<max(0ll,n-mk)<<"\n";
	}
	return 0;
}
