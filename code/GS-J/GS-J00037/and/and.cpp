#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,two;
long long a[20];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=maxn){
			maxn==a[i];
		}
	}
	for(int j=0;j<n;j++){
		if(a[j]>=two&&maxn!=two){
			two==a[j];
		}
	}
	cout<<two;
	return 0;
}
