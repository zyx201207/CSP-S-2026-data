#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long qua,arr[N],sum;
char cha[N];
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>qua;
	for(int m=1;m<=qua;m++)
	{
		cin>>arr[m]>>cha[m];
		for(int n=1;n<=arr[m];n++)str+=cha[m];
	}
	int len=str.size();
	for(int m=0;m<=len/2-1;m++)
	{
		long long ind=len-m-1;
		if(str[m]!=str[ind])sum++;
	}
	cout<<sum;
}
