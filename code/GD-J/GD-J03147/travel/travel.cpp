#include<bits/stdc++.h>
using namespace std;
bool kao(string a,string b)
{
	if(a=="A"&&b=="B")return 1;
	if(a=="B"&&b=="A")return 1;
	if(a=="B"&&b=="C")return 1;
	if(a=="C"&&b=="B")return 1;
	if(a=="F"&&b=="D")return 1;
	if(a=="D"&&b=="F")return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
//	for(int i=0;i<3;i++)scanf("%s",&c1[i]);
//	for(int i=0;i<3;i++)scanf("%s",&s1[i]);
//	for(int i=0;i<3;i++)scanf("%s",&c2[i]);
//	for(int i=0;i<3;i++)scanf("%s",&s2[i]);
	cin>>c1>>s1>>c2>>s2;
//	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		printf("1");
		if(s1[0]+s1[1]==s2[0]+s2[1])
		{
			printf("1");
//			if((s1[2]=="A"||s1[2]=="B"||s1[2]=="C")&&(s2[2]=="A"||s2[2]=="B"||s2[2]=="C"))
//			{
//				printf("1");
//				cout<<kao(s1[2],s2[2]);
//				if(kao(s1[2],s2[2]))
//				{
//					printf("1");
//				}
//			}
//			else if((s1[2]=="D"||s1[2]=="F")&&(s2[2]=="D"||s2[2]=="F"))
//			{
//				printf("1");
//				if(kao(s1[2],s2[2]))
//				{
//					printf("1");
//				}
//			}
		}
	}
	return 0;
}
//(s1[2]=="A"&&s2[2]=="B")||
//02 01A 02 01B
