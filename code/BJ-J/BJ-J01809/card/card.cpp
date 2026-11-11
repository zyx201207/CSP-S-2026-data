#include<bits/stdc++.h>
int const N=1e5+10;
int a[N];
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i=0,num=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<a[i]+a[i+1];
	cout<<a[i]-a[i+1];
	for(int j=0;j<n;j++){
		num+=a[j];
		}
	cout<<num-a[i]-a[i+1];
	return 0;
	}
