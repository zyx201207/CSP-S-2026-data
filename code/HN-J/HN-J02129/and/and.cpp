#include<bits/stdc++.h>
using namespace std;
int d=900000005;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=0,n,m,a[d],b,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//b++
	}
	c=1+(m+n-1)*(n-m);
	if(m=2)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1];
		if(ans<b)ans=b;
	    }
	}else if(m=3)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1]&a[i+2];
		if(ans<b)ans=b;
	    }
	}else if(m=4)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1]&a[i+2]&a[i+3];
		if(ans<b)ans=b;
	    }
	}else if(m=5)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4];
		if(ans<b)ans=b;
	    }
	}else if(m=6)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5];
		if(ans<b)ans=b;
	    }
	}else if(m=7)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+m-1];
		if(ans<b)ans=b;
	    }
	}else if(m=8)
	{
		for(int i=1;i<=c;i++)
	    {
		b=a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4]&a[i+5]&a[i+m-2]&a[i+m-1];
		if(ans<b)ans=b;
	    }
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
