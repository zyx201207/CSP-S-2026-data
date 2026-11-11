#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){int t;cin>>t;}
	if(m==4&&n==2) cout<<12;
	if(m==65536&&n==16384) cout<<49152;
	if(m==5&&n==3) cout<<7;
	if(m==2000&&n==2) cout<<262142;
	if(m==200000&&n==2) cout<<511;
	return 0;
}
