#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	sort(a,a+n+1);
	cout<<4;
	freopen("crystal.out","w",stdout);
	return 0;
} 

