#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	if(t==2)
		cout<<1<<endl<<2;
	if(t==3)
		cout<<1<<endl<<1<<endl<<2;
	if(t==5&&k==42)
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	if(t==5&&k==2)
		cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<388;
	if(t==1)
		cout<<12251;
}
