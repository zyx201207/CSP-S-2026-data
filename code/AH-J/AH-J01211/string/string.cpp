#include<bits/stdc++.h>
using namespace std;
int a[]={0};
string s,c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,flag=0,add=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            add++;
            s[add]=c[i];
        }
    }
    if(add==1)
    {
		flag=0;
	}
    else if(add%1==0)
    {
		for(int i=1;i<=add/2;i++)
        {
			int j=add;
		    if(s[i]!=s[j])
		    {
				flag=1;
			}
		    j--;
	    }
	}
    if(flag==0)
    {
		cout<<"0";
	}
	else if(flag==1)
	{
		cout<<"2";
	}
    return 0;
}
