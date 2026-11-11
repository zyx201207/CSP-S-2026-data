#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2000020;

ll x[MAXN] ;
int befo[MAXN] , to[MAXN];
ll ans,d;
int n;
int last=1,nex;
 inline ll read()
{
	register ll res=0ll,flag=1ll;
	char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch = '-')flag=-1;
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res*flag;
}

inline void lower(int i)
{
	while(true){
	if(x[i]-x[last]<=d){befo[i]=last;return;}
	last++;
	}
}
inline void upper(int i)
{
	while(true){
	if(x[nex]-x[i]<=d){to[i]=nex;return;}
	nex--;
	}
}
int rou=0;
int s,ta;
bool findr(int n)
{
	int i=min(to[n],ta);
	int j=max(befo[i],s);
	if(j==n)
	{
		if(i==ta)
		{
		if(rou)return true;
		else return false;
		}
		else
		{
			return findr(i);
		}	
	}
	else if(n-j==1)
	{
		if(i==ta)
		{
		if(!rou)return true;
		else return false;
		}
		else
		{
			if(rou)return false;
			else {
				rou+=1;
			return findr(i);}
		}
	}
	else
	{
		return false;
	}
}
int c,t;
int dot0,dot1,t0,t1;
int main()
{
	freopen("migrate.in", "r" ,stdin);
	freopen("migrate.out.txt", "w" , stdout);
	c=read(),t=read();
	for(int k=1;k<=t;k++){
	n=read(),d=read();
	nex=n;
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++)lower(i);
	for(int i=n;i>=1;i--)upper(i);
	for(int i=1;i<=n;i++)
	{
		/*t0=t1=0;
		int j,k;
		if(to[i]!=i){
		dot0=to[i];t0=1;}
		while(t0)
		{
			j=dot0;
			k=to[j];
			if(j==k)t0=0;
			else if(j==befo[k])dot0=k;
			else if(j-max(befo[k],i+1)==1){dot1=k;t1=1;break;}
			for(int l=j+1;l<k;l++)if(j-max(befo[l],i+1)==1)ans++;
		}
		while(t1)
		{
			j=dot1;
			k=to[j];
			if(j==befo[k])dot1=k,ans++;
			else t1=0;
			for(int l=j+1;l<k;l++)if(j==befo[l])ans++;
		}*/
		for(int j=i+1;j<=n;j++)
		{
			if(to[to[to[to[to[to[i]]]]]]<befo[j])break;
			rou=0,s=i,ta=j;
			if(findr(s))ans++;
		}
	}
	cout<<ans<<endl;
	}
		fclose(stdin);
	fclose(stdout);
	return 0;
}