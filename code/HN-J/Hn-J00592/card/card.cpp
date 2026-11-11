#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=1;
	cin>>n>>m;
	int a[n],b[m];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(m==n){
		for(int i=m;i>=1;i--)cout<<i<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
 return 0;
}
