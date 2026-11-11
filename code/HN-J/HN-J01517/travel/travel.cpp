#include<bits/stdc++.h>
using namespace std;
int main() 
{
	feopen("travel.in","r","stdin");
	feopen("travel.out","w","stdout");
	int i,j,s1=0,s2=0,s3=0,s4=0;
	string a;
	cin>>a;
	if(a[0]==a[3])
	{
		s1=1;
		for(i=0; i<5; i++) {
			a[1]=a[1]-('A'+(i+'0'));
			a[3]=a[3]-('A'+(i+'0'));
			if(a[1]==a[3])
			{
				s2++;
			}
		}
	}
	cout<<s1<<s2<<s2<<s4;
	return 0;
}
