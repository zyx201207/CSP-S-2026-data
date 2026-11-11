#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,a,b;
	cin>>n>>a>>m>>b;
	if(n==m) cout<<"1";
	else cout<<"0";
	if(n==m && a[0]==b[0] && a[1]==b[1]) cout<<"1";
	else cout<<"0";
	if(a[2]>b[2]) swap(a,b);
	if(n==m && a[0]==b[0] && a[1]==b[1] && (a[2]=='A' && b[2]=='B' || a[2]=='A' && b[2]=='C' || a[2]=='B' && b[2]=='C' || a[2]=='D' && b[2]=='F')) cout<<"1";
	else cout<<"0";
	if(n==m && a[0]==b[0] && a[1]==b[1] && (a[2]=='A' && b[2]=='B' || a[2]=='B' && b[2]=='C' || a[2]=='D' && b[2]=='F')) cout<<"1";
	else cout<<"0";
	return 0;
}
