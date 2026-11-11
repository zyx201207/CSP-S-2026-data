#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string a;
	int q;
	string s;
	int w=0;
	for (int i=1;i<=n;i++)
	{
		cin >>q;
		cin >> s;
		w+=q;
		for (int j=1;j<=q;j++)
		{
			a+=s;
		}
	 } 
	 int num=0;
	 for (int i=1;i<=w/2;i++)
	 {
	 	if (a[i-1]!=a[w-i])
	 	{
	 		num++;
		 }
	 }
	 cout << num;
 } 
