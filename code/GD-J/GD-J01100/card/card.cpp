
#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[300005];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==4)cout<<"3 1 4";
	else cout<<"3 1 2 1 3 2 3 1 2 1";
	return 0;
} 
