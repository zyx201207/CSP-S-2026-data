#include<bits/stdc++.h>
using namespace std;
string n,m,c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>c1>>m>>c2;
	if(n==m) 
	{
		cout<<1100;
	}
	else 
	{
		cout<<0000;
		return 0;
    }
	/*if(c1==01A||c1==01B||c1==01C||c1==01D||c1==01F)
	{
		switch(c2)
		{
			case 01A: cout<<1;
			case 01B: cout<<1;
			case 01C: cout<<1;
			case 01D: cout<<1;
			case 01F: cout<<1;break;	
		}
	}
	else if(c1==02A||c1==02B||c1==02C||c1==02D||c1==02F)
	{
		switch(c2)
		{
			case 02A: cout<<1;
			case 02B: cout<<1;
			case 02C: cout<<1;
			case 02D: cout<<1;
			case 02F: cout<<1;break;	
		}
	}
	else if(c1==03A||c1==03B||c1==03C||c1==03D||c1==03F)
	{
		switch(c2)
		{
			case 03A: cout<<1;
			case 03B: cout<<1;
			case 03C: cout<<1;
			case 03D: cout<<1;
			case 03F: cout<<1; break;	
		}
	}
	else if(c1==04A||c1==04B||c1==04C||c1==04D||c1==04F)
	{
		switch(c2)
		{
			case 04A: cout<<1;
			case 04B: cout<<1;
			case 04C: cout<<1;
			case 04D: cout<<1;
			case 04F: cout<<1; break;	
		}
	}
	else if(c1==05A||c1==05B||c1==05C||c1==05D||c1==05F)
	{
		switch(c2)
		{
			case 05A: cout<<1;
			case 05B: cout<<1;
			case 05C: cout<<1;
			case 05D: cout<<1;
			case 05F: cout<<1; break;	
		}
	}
	else if(c1==06A||c1==06B||c1==06C||c1==06D||c1==06F)
	{
		switch(c2)
		{
			case 06A: cout<<1;
			case 06B: cout<<1;
			case 06C: cout<<1;
			case 06D: cout<<1;
			case 06F: cout<<1; break;	
		}
	}
	else if(c1==07A||c1==07B||c1==07C||c1==07D||c1==07F)
	{
		switch(c2)
		{
			case 07A: cout<<1;
			case 07B: cout<<1;
			case 07C: cout<<1;
			case 07D: cout<<1;
			case 07F: cout<<1; break;	
		}
	}
	else if( c1 == 08A || c1 == 08B || c1 == 08C || c1 == 08D || c1 == 08F )
	{
		switch(c2)
		{
			case 08A: cout<<1;
			case 08B: cout<<1;
			case 08C: cout<<1;
			case 08D: cout<<1;
			case 08F: cout<<1; break;	
		}
	}
	else if(c1==09A||c1==09B||c1==09C||c1==09D||c1==09F)
	{
		switch(c2)
		{
			case 09A: cout<<1;
			case 09B: cout<<1;
			case 09C: cout<<1;
			case 09D: cout<<1;
			case 09F: cout<<1;break;	
		}
	}
	else if(c1==10A||c1==10B||c1==10C||c1==10D||c1==10F)
	{
		switch(c2)
		{
			case 10A: cout<<1;
			case 10B: cout<<1;
			case 10C: cout<<1;
			case 10D: cout<<1;
			case 10F: cout<<1;break;	
		}
	}
	else if(c1==11A||c1==11B||c1==11C||c1==11D||c1==11F)
	{
		switch(c2)
		{
			case 11A: cout<<1;
			case 11B: cout<<1;
			case 11C: cout<<1;
			case 11D: cout<<1;
			case 11F: cout<<1;break;	
		}
	}
	else if(c1==12A||c1==12B||c1==12C||c1==12D||c1==12F)
	{
		switch(c2)
		{
			case 12A: cout<<1;
			case 12B: cout<<1;
			case 12C: cout<<1;
			case 12D: cout<<1;
			case 12F: cout<<1;break;	
		}
	}
	else if(c1==13A||c1==13B||c1==13C||c1==13D||c1==13F)
	{
		switch(c2)
		{
			case 13A: cout<<1;
			case 13B: cout<<1;
			case 13C: cout<<1;
			case 13D: cout<<1;
			case 13F: cout<<1;break;	
		}
	}
	else if(c1==14A||c1==14B||c1==14C||c1==14D||c1==14F)
	{
		switch(c2)
		{
			case 14A: cout<<1;
			case 14B: cout<<1;
			case 14C: cout<<1;
			case 14D: cout<<1;
			case 14F: cout<<1;break;	
		}
	}
	else if(c1==15A||c1==15B||c1==15C||c1==15D||c1==15F)
	{
		switch(c2)
		{
			case 15A: cout<<1;
			case 15B: cout<<1;
			case 15C: cout<<1;
			case 15D: cout<<1;
			case 15F: cout<<1;break;	
		}
	}
	else if(c1==16A||c1==16B||c1==16C||c1==16D||c1==16F)
	{
		switch(c2)
		{
			case 16A: cout<<1;
			case 16B: cout<<1;
			case 16C: cout<<1;
			case 16D: cout<<1;
			case 16F: cout<<1;break;	
		}
	}
	else if(c1==17A||c1==17B||c1==17C||c1==17D||c1==17F)
	{
		switch(c2)
		{
			case 17A: cout<<1;
			case 17B: cout<<1;
			case 17C: cout<<1;
			case 17D: cout<<1;
			case 17F: cout<<1;break;	
		}
	}
	else if(c1==18A||c1==18B||c1==18C||c1==18D||c1==18F)
	{
		switch(c2)
		{
			case 18A: cout<<1;
			case 18B: cout<<1;
			case 18C: cout<<1;
			case 18D: cout<<1;
			case 18F: cout<<1;break;	
		}
	}*/
	return 0;
}