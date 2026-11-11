#include<bits/stdc++.h>
using namespace std;
struct data{
	char c;
	unsigned long long len,s;
}a[200001];
unsigned long long minn(unsigned long long a,unsigned long long b)
{
	if(a<=b) return a;
	return b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    unsigned long long l=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		 cin>>a[i].len>>a[i].c;
		 l+=a[i].len;a[i].s=l;
	}
    unsigned long long bi=l/2,le=0,rst=0,lp=1,rp=l,lp2=1,rp2=n,ans=0;
    if(l%2==0)
    {
		le=bi;rst=bi+1;
	}
	if(l%2==1) 
	{
		le=bi;rst=bi+2;
	}
	unsigned long long tl1=0,tl2=0;
	while(lp<=le&&rp>=rst&&lp!=rp)
	{
		char x1=a[lp2].c,x2=a[rp2].c;
		if(tl1==0) tl1=a[lp2].len;
		if(tl2==0) tl2=a[rp2].len;
		unsigned long long k=minn(tl1,tl2);
		if(x1!=x2)
		{
		    ans+=k;
	    }
		if(tl1<tl2)
		{
			 tl1=0;tl2-=k;lp2++;
		}
		if(tl2<tl1)
		{
			tl2=0;tl1-=k;rp2--;
		} 
		if(tl1==tl2)
		{
			tl1=0;lp2++;tl2=0;rp2--;
		}
		lp+=k;rp-=k;
	}
	cout<<ans;
	return 0;
}
