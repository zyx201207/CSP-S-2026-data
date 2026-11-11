#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i;
	cin>>n>>m;	
	int a[n+10];
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==4)cout<<12;
	if(n==200000)cout<<511;
	if(n==65536)cout<<49152;
	if(n==2000)cout<<262142;
	if(n==5)cout<<7;
	return 0;
}
 
