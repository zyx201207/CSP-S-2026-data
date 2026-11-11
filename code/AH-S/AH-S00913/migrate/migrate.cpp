#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=305;
ll tu[Maxn][Maxn];
ll ans[Maxn][Maxn];
struct FastScanner
{
	static const int SZ=1<<20;
	int idx=0, size=0;
	char buf[SZ];
	inline char readChar()
	{
		if(idx>=size)
		{
			size=(int)fread(buf,1,SZ,stdin);
			idx=0;
			if(size==0) return 0;
		}
		return buf[idx++];
	}
	template <class T> bool readInt(T &out)
	{
		char c=readChar();
		if(!c) return false;
		while(c!='-' && (c<'0' || c>'9'))
		{
			c=readChar();
			if(!c) return false;
		}
		T sign=1;
		if(c=='-')
		{
			sign=-1;
			c=readChar();
		}
		T num=0;
		while(c>='0' && c<='9')
		{
			num=num*10+(c-'0');
			c=readChar();
		}
		out=sign*num;
		return true;
	}
}fs;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, T;
	fs.readInt(c);
	fs.readInt(T);
	while(T--)
	{
		int n;
		ll d;
		fs.readInt(n);
		fs.readInt(d);
		vector<ll> a(n+5);
		for(int i=1;i<=n;i++)
		{
			fs.readInt(a[i]);
		}
		if(n<=3)
		{
			printf("0\n");
			continue;
		}
		memset(tu,0x3f,sizeof(tu));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			tu[i][i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					tu[i][j]=1;
					ans[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(tu[i][k]+tu[k][j]<tu[i][j])
					{
						tu[i][j]=tu[i][k]+tu[k][j];
						ans[i][j]=1LL*ans[i][k]*ans[k][j];
					}
					else if(tu[i][k]+tu[k][j]==tu[i][j])
					{
						ans[i][j]+=1LL*ans[i][k]*ans[k][j];
					}
				}
			}
		}
		// for(int i=1;i<=n;i++)
		// {
		// 	for(int j=i+1;j<=n;j++)
		// 	{
		// 		if(n<=10) cout << tu[i][j] << " ";
		// 	}
		// 	if(n<=10) cout << "\n";
		// }
		ll cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				// if(n<=10) cout << ans[i][j] << " ";
				if(ans[i][j]==2) cnt++;
			}
			// if(n<=10) cout << "\n";
		}
		printf("%lld\n",cnt);
	}
	return 0;
}