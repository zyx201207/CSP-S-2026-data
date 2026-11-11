#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1>>a[1]>>a[2]>>a[3]>>c2>>b[1]>>b[2]>>b[3];
	int s1=(a[1]-'0')*10+a[2]-'0';
	int s2=(b[1]-'0')*10+b[2]-'0';
	if(c1==c2)cout<<1;
	else
	{
	    cout<<"0000";
	    return 0;
    }
	if(s1==s2)cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(a[3]=='A'||a[3]=='B'||a[3]=='C')
	{
		if(b[3]=='A'||b[3]=='B'||b[3]=='C')
		{
			cout<<1;
			if(a[3]-b[3]==-1||a[3]-b[3]==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(a[3]=='D'||a[3]=='E')
	{
		if(b[3]=='D'||b[3]=='E')
		{
			cout<<11;
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}

	return 0;
} 
