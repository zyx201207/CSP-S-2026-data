//GZ-J00040 贵阳市第二实验中学 岑钰欣 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) 
{
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
    string c1,c2,s1,s2;
    int t=1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
	{
		printf("%d",t);
	} 
    else 
	{
	    t=0; 
	    printf("%d",t);
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		printf("%d",t);
	} 
    else 
	{
	    t=0;
		printf("%d",t);
	}
	if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))
	{
		printf("%d",t);
	} 
    else 
	{
	    t=0;
		printf("%d",t);
	}
    if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1))
	{
		printf("%d",t);
	} 
    else 
	{
	    t=0;
		printf("%d",t);
	}
	return 0;
}
