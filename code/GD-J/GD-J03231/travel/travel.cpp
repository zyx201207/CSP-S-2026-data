#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m)
	{
		cout<<1;
		int ans=(a[0]-'0')*10+(a[1]-'0');
		int bns=(b[0]-'0')*10+(b[1]-'0');
		if(ans==bns)
		{
			cout<<1;
			if((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D'))
			{
				cout<<1;
				if(abs(a[2]-b[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
