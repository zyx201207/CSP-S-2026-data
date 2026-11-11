#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c;
string n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a[1]>>a[2]>>a[3];
	cin>>m>>b[1]>>b[2]>>b[3];
	if(n==m)cout<<1;
	else cout<<0;
	if(n==m&&a[1]==b[1]&&a[2]==b[2])cout<<1;
	else cout<<0;
	if(n==m&&a[1]==b[1]&&a[2]==b[2]&&((a[3]<='C'&&b[3]<='C')||(a[3]>='D'&&b[3]>='D')))cout<<1;
	else cout<<0;
	if(n==m&&a[1]==b[1]&&a[2]==b[2]&&((a[3]<='C'&&b[3]<='C')||(a[3]>='D'&&b[3]>='D'))&&abs(a[3]-b[3])==1)cout<<1;
	else cout<<0;
}
//Trick||Treat!
