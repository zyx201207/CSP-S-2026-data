#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int c,t;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin); 
		freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int len=2;i+len-1<=n;len++)
			{
				int j=len+i-1;
				int cnt1=0,p=i+1,st=i,cnt2=0,fl=0;
				while(p<=j)
				{
					while(p<=j&&x[p]-x[st]<=d) p++;
					cnt1++,st=p-1;
					if(x[p]-x[st]>d)
					{
						fl=1;
						break;
					}
				}
				if(fl) continue;
				p=i+2,st=i;
				while(p<=j)
				{
					while(p<=j&&x[p]-x[st]<=d) p++;
					cnt2++,st=p-1;
				}
				if(cnt2+1==cnt1) ans++;
			}
		cout<<ans/2<<'\n';
	}
}
