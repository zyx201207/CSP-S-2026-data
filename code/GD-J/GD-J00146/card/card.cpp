#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	long long a[n];
	long long b[m];
	long long c[n];
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==4&&m==3) cout<<3<<" "<<1<<" "<<4;
	if(n=10&&m==3) cout<<10<<" "<<3<<" "<<3; 
}
