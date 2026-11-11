#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0;
	int a,b,c[4];
	char rz[3],xz[3];
	cin>>a;
	for(int i=1;i<=3;i++) cin>>rz[i];
	cin>>b;
	for(int i=1;i<=3;i++) cin>>xz[i];
	if(a==b)
	{
		c[1]=1;
		cout<<c[1];
		for(int i=1;i<=2;i++)
		{
			if(rz[i]!=xz[i]) f=1;
		}
		if(f==0) cout<<1;
		else cout<<0;
		if(f==0)
		{
			if(rz[3]=='A'&&(xz[3]=='B'||xz[3]=='C') || xz[3]=='A'&&(rz[3]=='B'||rz[3]=='C') || rz[3]=='D'&&xz[3]=='F' || xz[3]=='D'&&rz[3]=='F')
			cout<<1;
			else cout<<0;
			if(rz[3]=='B'&&(xz[3]=='A'||xz[3]=='C') || xz[3]=='B'&&(rz[3]=='A'||rz[3]=='C') || rz[3]=='D'&&xz[3]=='F' || xz[3]=='D'&&rz[3]=='F')
			cout<<1;
		    else cout<<0;
		}
		else cout<<0<<0;
	} 
	else cout<<0<<0<<0<<0;
	return 0; 
}
