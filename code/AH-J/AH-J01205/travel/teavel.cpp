#include<bits/stdc++.h>
int a,b,c,d;
char e,f;
void cta(char o,char p)
{
	if(o=='A')
	{
		if(p=='A'||p=='B') std::cout<<"1";
		else std::cout<<"0";
	}
	else if(o=='C')
	{
		if(p=='B'||p=='C') std::cout<<"1";
		else std::cout<<"0";
	}
	else if(o=='B')
	{
		if(p=='A'||p=='C') std::cout<<"1";
		else std::cout<<"0";
	}
	else if(o=='D')
	{
		if(p=='F') std::cout<<"1";
		else std::cout<<"0";
	}
	else if(o=='F')
	{
		if(p=='D') std::cout<<"1";
		else std::cout<<"0";
	}
	else std::cout<<"0";
}
int main()
{
	std::freopen("travel.in","r",stdin);
	std::freopen("travel.out","w",stdout);
	std::cin >>a;
	std::cin >>b;
	std::cin >>e;
	std::cin >>c;
	std::cin >>d;
	std::cin >>f;
	if(a==c) 
	{
		std::cout<<"1";
		if(b==d) 
		{
			std::cout<<"1";
			if(e=='A'||e=='B'||e=='C')
			{
				if(f=='A'||f=='B'||f=='C') 
				{
					std::cout<<"1";
					cta(e,f);
				}
				else std::cout<<"00";
			}
			else if(e=='D'||e=='F')
			{
				if(f=='D'||f=='F') 
				{
					std::cout<<"1";
					cta(e,f);
				}
				else std::cout<<"00";
			}
			else std::cout<<"00";
		}
		else std::cout<<"000";
	}
	else std::cout<<"0000";
	return 0;
}
