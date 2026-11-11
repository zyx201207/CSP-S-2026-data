#include<bits/stdc++.h>
using namespace std;
long long a,c,n1,n2,n3;
char b[5],d[5];
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=1;i<=3;i++)cin>>b[i];
	cin>>c;
	for(int i=1;i<=3;i++)cin>>d[i];
	if(a==c)
	{
		cout<<1;
		if(b[1]==d[1]&&b[2]==d[2])
		{
			n1=1;
			if(((b[3]=='A'||b[3]=='B'||b[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C'))||((b[3]=='D'||b[3]=='F')&&(d[3]=='D'||d[3]=='F')))
			{
				n2=1;
				if(abs(b[3]-d[3])==1||((b[3]=='D'||b[3]=='F')&&(d[3]=='D'||d[3]=='F')))n3=1;
			}
		}
	}
	else cout<<0;
	if(n1==1)cout<<1;
	else cout<<0;
	if(n2==1)cout<<1;
	else cout<<0;
	if(n3==1)cout<<1;
	else cout<<0;
	return 0;
}
