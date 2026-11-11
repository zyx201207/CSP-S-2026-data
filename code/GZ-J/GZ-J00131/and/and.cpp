//准考证号：GZ- J00131  学校：遵义市新蒲新区滨湖中学  姓名：刘睿澜
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long int n,m,a[100005],sum,num=0;
    string s,s1,s2;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	int e=a[i];
    	while(e>0)
    	{
	    	if(e%2==0)
	    	{
		    	s+='0';
	    	}
			else s+='1';
			e/=2;
	    }
	   	int b=s.size()/2;
	   	int r=s.size()
	   	for(int j=1;j<b;j++)
	   	{
	   		int g=s[j];
	   		s[j]=s[r-j-1];
	   		s[r-j-1]=g;
	    }
	    
	    s=' ';
	   
	}
	for(int i=n;i>m;i--)
	{
		
	}

	
	return 0;
 } 
