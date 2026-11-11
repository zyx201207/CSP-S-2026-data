#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;


long long n,m,a[N],b[N],an=1,p,ll=1;
//bool check(int x){
//	int h=x-1,p=m;
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int o=time(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	
	for(int i=2;i<=n;i++){
		p=m;
		int j=i;
		while(b[j]*ll<=p&&j<=n){
			
		
			p-=b[j]*ll;
			ll++;
			j++;
			
		}
		an=max(ll,an);
		ll=1;
		
	}
	
	
	
	
	
	cout<<an<<'\n';
	//cout<<o/100000000;
	return 0;
}
