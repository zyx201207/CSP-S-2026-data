#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		if(m>=(a[i+1]-a[i])*i) {
		m-=(a[i+1]-a[i])*i;
		b++;}
		else break;
		}
		cout<<b;
	return 0;
}


 
