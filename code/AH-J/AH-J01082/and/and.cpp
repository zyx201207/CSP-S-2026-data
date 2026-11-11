#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[214514];
string lll(int n,int wei)
{
	string k="";
	for(int i=0;i<wei;i++)
		k+=(char)((n%2)+'0'),n/=2;
	k+=" ";
	reverse(k.begin(),k.end());
	return k;
}
int fan_1(int n)
{
	int ans=0;
	for(int i=0;i<20;i++)
		ans+=(n%2),n/=2;
	return ans;
}
int pow_2[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int maxn=-1,kkk;
    cin>>a[1],kkk=a[1];
    for(int i=2;i<=n;i++)
    {
		cin>>a[i];
		kkk&=a[i];
		maxn=max(maxn,a[i]);
	}
    if(m==1) cout<<maxn,exit(0);
    if(m==n) cout<<kkk,exit(0);
    bool flag=false;
    for(int i=0;i<19;i++)
		if(a[1]==pow_2[i]) flag=true;
	if(flag==true&&n>20)
	{
		int tong[30];
		memset(tong,0,sizeof(tong));
		for(int i=1;i<=n;i++)
			tong[fan_1(a[i])]++;
		for(int i=29;i>=0;i--)
		{
			m-=tong[i];
			if(m<0) cout<<pow(2,i)-1,exit(0);
		}
	}
    if(m<=20&&n<=20)
    {
		int maxk=-1;
		for(int i=1;i<pow(2,n);i++)
		{
			string ls=lll(i,n);
			int sum=0;
			for(int j=1;j<ls.size();j++)
				sum+=(ls[j]=='1');
			if(sum==m)
			{
				int kkk=LONG_LONG_MAX;
				for(int j=1;j<ls.size();j++)
					if(ls[j]=='1') kkk&=a[j];
				maxk=max(maxk,kkk);
			}
		}
		cout<<maxk;
		exit(0);
	}
    cout<<0;
    return 0;
}
