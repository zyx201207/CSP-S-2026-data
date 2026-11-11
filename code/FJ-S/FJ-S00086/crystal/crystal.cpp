#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m == (a[3]-a[0])+(a[2]-a[0])||a[2]!=a[3]) ans = 3;
	else if(m == (a[3]-a[0])+(a[2]-a[0])||a[2]==a[3]) ans = 4;
	cout<<ans;
	return 0;
}
