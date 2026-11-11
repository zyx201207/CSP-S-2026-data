#include<bits/stdc++.h>
using namespace std;
char a[7],c[7],b[8],d[8];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int p=0;
	for(int i=1;i<=2;i++)
    cin>>a[i];	
	for(int i=1;i<=3;i++)
    cin>>b[i];	
    for(int i=1;i<=2;i++)
    cin>>c[i];	
    for(int i=1;i<=3;i++)
    cin>>d[i];	
    if(a[1]==c[1]&&a[2]==c[2])cout<<1;
    else cout<<0;
    if(a[1]==c[1]&&a[2]==c[2]&&b[1]==d[1]&&b[2]==d[2])cout<<1;
    else cout<<0;
    if(a[1]==c[1]&&a[2]==c[2]&&b[1]==d[1]&&b[2]==d[2])
	{
		if(b[3]<='C'&&d[3]<='C') 
		{
			cout<<1;
			p=1;
		}
		else if(b[3]>'C'&&d[3]>'C') 
		{
			cout<<1;
			p=1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(p==1)
	{
		if(b[3]-d[3]==1||d[3]-b[3]==1)
		cout<<1;
		else cout<<0;
	}
    else cout<<0;
	return 0;
} 
