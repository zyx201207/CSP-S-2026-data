#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long duanshu=0,geshu=0,zifushu=0;
	string letter,zifu="";
	long long count=0;
	
	cin>>duanshu;
	for (int i=0;i<duanshu;i++)
	{
		cin>>geshu>>letter;
		zifushu+=geshu;
		for (int j=0;j<geshu;j++)
		{
			zifu=zifu+letter;
		}
	}
	
	for (int i=0;i<zifushu/2;i++)
	{
		if (zifu[i]!=zifu[zifushu-1-i])
		count+=1;
	}
	
	cout<<count<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
