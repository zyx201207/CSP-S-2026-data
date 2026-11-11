#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
struct node
{
	int num;
	char c;
}a[MAXN];
int n,len,ans;
char mid;
signed main(  )
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		len+=a[i].num;
	}
	if(len%2==1)
	{
		int tmp=len/2,pos;
		node new_;
		for(int i=1;i<=n;i++)
		{ 
			tmp-=a[i].num;
			if(tmp<0) {mid=a[i].c,new_=(node){-tmp-1,a[i].c},a[i].num-=(-tmp),pos=i;break;}
		}
		int lenz=a[pos].num,leny=new_.num;
		if(lenz>leny) lenz-=leny,leny=0;
		else leny-=lenz,lenz=0;
		int l=pos,r=pos+1;
		char lc=a[pos].c,rc=new_.c;
		while(l>=1&&r<=n+1)
		{
			if(leny==0) leny=a[r++].num,rc=a[r-1].c;
			else lenz=a[--l].num,lc=a[l].c;
			if(lc!=rc) ans+=min(lenz,leny);
			if(lenz>leny) lenz-=leny,leny=0;
			else leny-=lenz,lenz=0;
		}
		cout<<ans;
	}
	else
	{
		int tmp=len/2,pos;
		node new_;
		for(int i=1;i<=n;i++)
		{ 
			tmp-=a[i].num;
			if(tmp<=0) {mid=a[i].c,new_=(node){-tmp,a[i].c},a[i].num-=(-tmp),pos=i;break;}
		}
		int lenz=a[pos].num,leny=new_.num;
		if(lenz>leny) lenz-=leny,leny=0;
		else leny-=lenz,lenz=0;
		int l=pos,r=pos+1;
		char lc=a[pos].c,rc=new_.c;
		while(l>=1&&r<=n+1)
		{
			if(leny==0) leny=a[r++].num,rc=a[r-1].c;
			else lenz=a[--l].num,lc=a[l].c;
			if(lc!=rc) ans+=min(lenz,leny);
			if(lenz>leny) lenz-=leny,leny=0;
			else leny-=lenz,lenz=0;
		}
		cout<<ans;
	}
}
