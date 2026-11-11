#include<iostream>
using namespace std;
struct Node
{int nb;
char ex;
	};
Node a[200000];
int main()
{
ios::sync_with_stdio(false);cin.tie(0);
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
int n,c=0;

int gs;
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i].nb>>a[i].ex;
}

for(int i=0;i<n;i++)
{
	gs+=a[i].nb;
}
gs/=2;

for(int i=0;i<n;i++)
{
	if(a[i].ex != a[n-1-i].ex)
	{
        while(a[i].nb > 0)
            {if(a[i].nb >= a[n-1-i].nb)
				{
					c+=a[n-1-i].nb;
	                a[i].nb-=a[n-1-i].nb;
	                a[n-1-i].nb=0;
	                a[n-1-i].ex=a[i].ex;
					i++;
				}
				else
	    { 
		c+=a[i].nb;
		a[i].nb=0;
		a[n-i-1].nb-=a[i].nb;
	}
					}
				
				}
	}

cout<<c;
return 0;
}
