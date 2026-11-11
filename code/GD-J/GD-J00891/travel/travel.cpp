#include<bits/stdc++.h>
using namespace std;
int n1,n2;
char m1,m2,m3,k1,k2,k3;
int main()
{
	cin >> n1>>m1>>m2>>m3>>n2>>k1>>k2>>k3;
	if(n1==n2)
	{
		cout<< 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(m1==k1&&m2==k2)
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if((m3=='D'||m3=='F')&&(k3=='D'||k3=='F'))
	{
		cout << 11;
		return 0;
	}
	else if(((m3=='D'||m3=='F')&&(k3!='D'||k3!='F'))||((m3!='D'||m3!='F')&&(k3=='D'||k3=='F')))
	{
		cout << "00";
		return 0;
	}
	else if(m3+1==k3||m3+2==k3||m3-1==k3||m3-2==k3)
	{
		cout << 1;
	}
	if(m3+1==k3||m3==k3+1)
	{
		cout << "1";
	}
	else
	{
		cout<<0;
		
	}
	return 0;
}
