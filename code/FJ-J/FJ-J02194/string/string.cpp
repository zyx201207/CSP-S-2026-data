#include<bits/stdc++.h>
using namespace std;
long long len,n,l,r,ans;bool tag;
struct sb
{
	long long num;char c;	
}a[200010];
int main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		tag=false;
		cin>>a[i].num>>a[i].c;
		if(a[i].c==a[i-1].c)a[i-1].num+=a[i].num,tag=true;
		len+=a[i].num;
		if(tag)i--,n--;
	}long long b=0,js=0;len=len%2?len/2+1:len/2;
	while(js<len)
		js+=a[++b].num;
	if(len%2==1)a[b].num--;
	if(js-len+1>a[b].num-(js-len+1)+1)l=b-1,r=b,a[b].num=2*(js-len+1)-a[b].num-1;
	else if(js-len<a[b].num-(js-len))l=b,r=b+1,a[b].num=a[b].num-2*(js-len+1)+1;
	else l=b-1,r=b+1;
	while(l!=0&&r!=n+1)
	{
		long long xg=min(a[l].num,a[r].num);
		if(a[l].c!=a[r].c)
			ans+=xg;
		if(xg==a[l].num&&xg==a[r].num)l--,r++;
		else if(xg==a[l].num)l--,a[r].num-=xg;
		else r++,a[l].num-=xg;
	}
	cout<<ans;
 	return 0;
}
