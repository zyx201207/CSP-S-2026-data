#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	int a[100]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=n)sum++;
	}
	cout<<sum<<endl;
	return 0;
} 
