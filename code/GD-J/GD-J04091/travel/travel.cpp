#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)

namespace marlin
{
	int ac,bc; string as,bs;
	bool contain(string a, char c)
	{
		for (int i=0;i<a.size();i++)
		{
			if (a[i]==c) return true;
		}
		return false;
	}
	void main()
	{
		cin>>ac>>as>>bc>>bs;
		bool a,b,c,d;
		a=b=c=d=false;
		if (ac==bc)
		{
			a=true;
			string aw;aw+=as[0];aw+=as[1];
			string bw;bw+=bs[0];bw+=bs[1];
			if (aw==bw)
			{
				b=true;
				char ax=as[2],bx=bs[2]; 
				if ((contain("ABC",ax)&&contain("ABC",bx))||
					(contain("DF",ax)&&contain("DF",bx)))
				{
					c=true;
					if (abs(short(ax)-short(bx))==1)
					{
						d=true;
					}
				}
			}
		}
		cout<<int(a)<<int(b)<<int(c)<<int(d); 
	}
}

signed main()
{
	WHENDEBUG{}else freopen("travel.in","r",stdin);
	WHENDEBUG{}else freopen("travel.out","w",stdout);
	marlin::main();
	return 0; 
}
