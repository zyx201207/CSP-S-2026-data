#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],sum;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	sum=a[n];
	m--;
	for(int i=n-1;i>=1;i--){
		if(m==0){
			break;
		}
		m--;
		sum=(sum & a[i]);	
	}
	cout<<sum;
	return 0;
}
