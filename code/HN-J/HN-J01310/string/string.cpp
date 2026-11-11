#include<bits/stdc++.h>
using namespace std;
int n,x,total;
char v;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=1,sum=0;
    while(n--)
    {
    	cin>>x>>v;
        sum+=x; 
        int ans=cnt+x;
    	for(int i=cnt;i<=ans;i++)
    	    s[i]=v;
    	cnt+=x;
	}
	bool flag=true;
	for(int i=1;i<=sum;i++)
	{
		if(s[i]!=s[sum+1-i])
		{
			flag=false;
			total++;
		}
	}
	if(flag)
		cout<<0;
	else
	    cout<<total/2;
    return 0;
}
