#include <bits/stdc++.h>
using namespace std;
const int N=1e8; 
long long n,m,ar[N],z,v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	z=1;
	for(int i=n;i>=1;i--){
		v=ar[i]-ar[z];
		if(v>m){
			n=n-1;
		}
		z++;
	}
	cout<<n;
	
 return 0;
}
