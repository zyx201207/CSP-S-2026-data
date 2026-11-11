#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define int long long
#define rd "%lld"

namespace marlin
{
	constexpr int N=2e5+5;
	int n;
	int ws[N],ls[N]; char d[N];
	void main()
	{
		scanf(rd,&n);
		for (register int i=0;i<n;i++)
		{
			scanf(rd,ls+i);
			cin>>d[i];
			if (i)
			ws[i]=ws[i-1]+ls[i-1];
		}
		int w=ws[n-1]+ls[n-1];
		int l=0,r=n-1;
		int ans=0;
		while (l<r)
		{
			WHENDEBUG printf("l. " rd " r. " rd "\n",l,r);
			while (l<r&&w-ws[r]-ls[r]<ws[l]+ls[l])
			{
				WHENDEBUG printf("l. " rd " r. " rd "\n",l,r);
				WHENDEBUG cout<<d[r]<<" " <<d[l]<<endl;
				if (d[r]!=d[l])
				{
					if (w-ws[r]<=ws[l]+ls[l])
					{
						ans+=min(ls[r],w-ws[r]-ws[l]);
						WHENDEBUG printf("ansa. " rd "\n",ans);
					}
					else
					{
						ans+=min(ls[r],ws[l]+ls[l]-max(ws[l],(w-ws[r]-ls[r]))); 
						WHENDEBUG printf("ansb. " rd "\n",ans);
					}
				}
				r--;
				if((!(w-ws[r]-ls[r]<ws[l]+ls[l]))&&(w-ws[r]>ws[l]+ls[l]))
				{
					r++;
					break;
				}
			}
			l++;
		}
		printf(rd,ans);
	}
}

signed main()
{
	WHENDEBUG freopen("string6.in","r",stdin);
	WHENDEBUG{}else freopen("string.in","r",stdin);
	WHENDEBUG{}else freopen("string.out","w",stdout);
	marlin::main();
	return 0; 
}
