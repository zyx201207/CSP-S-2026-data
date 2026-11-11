#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//cout<<"0000";
	char aa[20];
	
	for(int i=0;i<=10;i++)
	{
		cin>>aa[i];
	}
	
	int ab=1;
	
	if(aa[0]==aa[5]&&aa[1]==aa[6])
	{
		cout<<ab;
	}
	else
	{
	cout<<"0000";
	return 0;
	}
	
	if(aa[2]==aa[7]&&aa[3]==aa[8])
	{
		cout<<ab;
	}
	else
	{
	cout<<"1100";
	return 0;
	}
	
	if((aa[4]=="A"&&aa[9]=="C")||(aa[4]=="A"&&a[9]=="B")||(aa[4]=="B"&&a[9]=="C")||(aa[4]=="D"&&a[9]=="F"))
	{
		cout<<ab;
	}
	else
	{
	cout<<"1110";
	return 0;
	}
	
	if(aa[4]=="A"&&aa[9]=="B"||aa[4]=="B"&&aa[9]=="A")
	{
		cout<<ab;
	}
	else
	{
	cout<<"1111";
	return 0;
	}

	
}
