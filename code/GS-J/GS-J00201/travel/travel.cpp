#include<bits/stdc++.h>
using namespace std;
struct student
{
	string chexiang;
	char zuoweihao;
	int zuoweipai;
}s[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{	
		cin>>s[i].chexiang>>s[i].zuoweipai>>s[i].zuoweihao;
	}
	if(s[1].chexiang==s[2].chexiang)
	{
		cout<<1;
		if(s[1].zuoweipai==s[2].zuoweipai)
		{
			cout<<1;
			if(s[1].zuoweihao=='A'&&s[2].zuoweihao=='B'||s[1].zuoweihao=='B'&&s[2].zuoweihao=='A'||s[1].zuoweihao=='B'&&s[2].zuoweihao=='C'||s[1].zuoweihao=='C'&&s[2].zuoweihao=='B'||s[1].zuoweihao=='D'&&s[2].zuoweihao=='F'||s[1].zuoweihao=='F'&&s[2].zuoweihao=='D'||s[1].zuoweihao=='A'&&s[2].zuoweihao=='C'||s[1].zuoweihao=='C'&&s[2].zuoweihao=='A')
			{
				cout<<1;
				if(s[1].zuoweihao=='A'&&s[2].zuoweihao=='B'||s[1].zuoweihao=='B'&&s[2].zuoweihao=='A'||s[1].zuoweihao=='B'&&s[2].zuoweihao=='C'||s[1].zuoweihao=='C'&&s[2].zuoweihao=='B'||s[1].zuoweihao=='D'&&s[2].zuoweihao=='F'||s[1].zuoweihao=='F'&&s[2].zuoweihao=='D')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				 } 
			}
			else
			{
				cout<<0<<0;
			}
			
		}
		else
		{
			cout<<0<<0<<0;
		}
	} 
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
