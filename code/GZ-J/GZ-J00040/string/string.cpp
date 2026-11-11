//GZ-J00040 贵阳市第二实验中学 岑钰欣 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct String
{
	long long a;
	char c;
};
int main(int argc, char** argv)
{
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
    long long count=0;
    int n,b=0,c=0;
    cin>>n;
    String A[n];
    for(int i=0;i<n;i++)
    {
    	cin>>A[i].a>>A[i].c;
	}
    for(int i=0;i<(n+1)/2;i++)
	{
		if(A[i-b].a==A[n-1-i+c].a)
		{
		    if(A[i-b].c!=A[n-1-i+c].c) count+=A[i-b].a;	
		}
		else 
		{
			if(A[i-b].a>A[n-1-i+c].a)
			{
				if(A[i-b].c!=A[n-1-i+c].c) count+=A[n-1-i+c].a;
				A[i-b].a-=A[n-1-i+c].a;
				b++;
			}
			else 
			{
				if(A[i-b].c!=A[n-1-i+c].c) count+=A[i-b].a;
				A[n-1-i+c].a-=A[i-b].a;
				c++;
			}
		}
	}
	printf("%lld",count);	
	return 0;
}
