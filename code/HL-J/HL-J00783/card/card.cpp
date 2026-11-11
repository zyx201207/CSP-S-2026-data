#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[n]<<" "<<a[n-1]<<" "<<a[n-1]*2;
	}
	return 0;
}