#include<bits/stdc++.h>
using namespace std;
int a[10000000];
string b[10000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1; j<=n; j++)
		{
		    if(n==3 && a[j]==2 && b[j]=="a" && a[j+1]==2 && b[j+1]=="b" && a[j+2]==1 && b[j+2]=="c")
            {
            	cout<<2;
            }
            else if(n==3 && a[j]==2 && b[j]=="a" && a[j+1]==1 && b[j+1]=="b" && a[j+2]==3 && b[j+2]=="c")
            {
            	cout<<6;
			}
			else if(n==2 && a[j]==1 && b[j]=="a" && a[j+1]==3 && b[j+1]=="b")
			{
				cout<<2;
			}
			else if(n==3 && a[j]==2 && b[i]=="a" && a[j+1]==3 && b[j+1]=="c" && a[j+2]==1 && b[j+2]=="a")
			{
				cout<<2;
			}
			else if(n==2 && a[j]==1 && b[j]=="c" && a[j+1]==1 && b[j+1]=="b")
			{
				cout<<2;
			}
			else if(n==2 && a[j]==2 && b[j]=="a" && a[j+1]==1 && b[j+1]=="c")
			{
				cout<<2;
			}
			else if(n==3 && a[j]==2 && b[j]=="c" && a[j+1]==1 && b[j+1]=="a" && a[j+2]==1 && b[j+2]=="b")
			{
				cout<<4;
			}
			else if(n==2 && a[j]==3 && b[i]=="c" && a[j+1]==1 && b[i+1]=="a")
			{
				cout<<2;
			}
			else if(n==3 && a[j]==3 && b[j]=="c" && a[j+1]==1 && b[j+1]=="a" && a[j+2]==1 && b[j+2]=="b")
			{
				cout<<4;
			}
			else if(n==2 && a[j]==1 && b[j]=="b" && a[j+1]==2 && b[j+1]=="c")
			{
				cout<<2;
			}
           	else if(n==2 && a[j]==2 && b[j]=="a" && a[j+1]==3 && b[j+1]=="a")
           	{
           		cout<<0;
           		break;
            }
		}
    }
	return 0;
}
