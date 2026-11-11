#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
int info[200005];//0=数量 
char info1[200005];//1=字母
long long alcnt[26];//每个字母的数量 
vector<int> aplst;//有的字母 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	int maxalph=0,cnta=0,maxain=0;
	//long long cnt=514514514503311451;
	for(int i=0;i<n;i++)
	{
		cin >> info[i]>>info1[i];
		alcnt[info1[i]-'a']+=info[i];
		maxalph=max(maxalph,info1[i]-'a');
	}
//	for(int i=0;i<n/2;i++)
//	{
//		
//	}
	for(int i=0;i<=maxalph;i++)
	{
		if(alcnt[i]!=0)
		{
			cnta++;
			aplst.push_back(i);
		}
	}
	if(cnta==1 || n==1)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==2)
	{
		int cnt=abs(aplst[0]-aplst[1]);
		if(n/2==0)cout<<cnt;
		if(n/2!=0 && min(alcnt[aplst[0]],alcnt[aplst[1]]) >= max(alcnt[aplst[0]],alcnt[aplst[1]]))cout<<cnt-1;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
