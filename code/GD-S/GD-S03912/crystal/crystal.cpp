#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k=0,mi=1000000000005;
int main(){
	cin>>n>>m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k+=a[i];
		} 
	k/=n;
	cout<<k++;
	return 0;
} 
