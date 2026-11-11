#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s;
	long long m;
}a[200010];
long long n,cnt,sum,ant;
string s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].m>>a[i].s;
    for(int i=1;i<=n/2+1;i++)
    {
    	long long ans=0,xxt;
    	xxt=min(ant,a[i].m);
    	ant-=xxt;
    	a[i].m-=xxt;
    	cnt+=xxt;
    	xxt=min(sum,a[n-i+1].m);
    	sum-=xxt;
    	a[n-i+1].m-=xxt;
    	cnt+=xxt;
    	if(a[i].s!=a[n-i+1].s)
    	{
    		ans=min(a[n-i+1].m,a[i].m);
    		a[i].m-=ans;
    		a[n-i+1].m-=ans;
    		sum+=a[i].m;
    		ant+=a[n-i+1].m;
    		cnt+=ans;
    	}
    	/*
    	if(a[i].m!=0)
    	{
    		ans=min(a[i].m,a[n-i].m);
    		a[i].m-=ans;
    		cnt+=ans;
    	}
    	*/
    	
    }
    cout<<cnt<<endl;
	return 0;
}
