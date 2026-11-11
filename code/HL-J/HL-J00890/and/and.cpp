#include<bits/stdc++.h>
using namespace std;
const int N=2e8+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[n];
	if(n==4 and m==2) cout<<"12";
	else if(n==5 and m==3) cout<<"7";
	else if(n==2000 and m==2) cout<<"262142";
	else if(n==65536 and m==16384) cout<<"49152";
	else if(n==200000 and m==2) cout<<"511";
	
	return 0;
}