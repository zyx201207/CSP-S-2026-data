#include<bits/stdc++.h>
using namespace std;

bool ans[5];

bool ABC_ce = false;

bool ce(char a,char b)
{
	if(a == 'A' || a == 'B' || a == 'C')
	{
		if(b == 'A' || b == 'B' || b == 'C')
		{
			ABC_ce = true;
			return true;
		}else{
			return false;
		}
	}else if(a == 'D' || a == 'F'){
		if(b == 'D' || b == 'F'){
			ABC_ce = false;
			return true;
		}else{
			return false;
		}
	}
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<5;i++)
	{
		ans[i] = false;
	}
	string Rnum,Xnum,Rseat,Xseat;
	cin>>Rnum>>Rseat>>Xnum>>Xseat;
	
	if(Rnum == Xnum)
	{
		ans[1] = true;
		if(Rseat[0] == Xseat[0] && Rseat[1] == Xseat[1])
		{
			ans[2] = true;
			if(ce(Rseat[2],Xseat[2])){
				ans[3] = true;
				if(ABC_ce == false)
				{
					ans[4] = true;
				}else{
					if(Rseat[2] == 'A' && Xseat[2] == 'C')
					{
						ans[4] = false;
					}else if(Rseat[2] == 'C' && Xseat[2] == 'A')
					{
						ans[4] = false;
					}else{
						ans[4] = true;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=4;i++)
	{
		cout<<ans[i];
	}
}
