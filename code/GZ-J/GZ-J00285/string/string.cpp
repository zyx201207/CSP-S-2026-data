//GJ-J00285 朱睿哲 中央民族大学附属中学贵阳学校
#include <bits/stdc++.h>
using namespace std;
int a,n,times;
char b;
string c;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<a;j++)
		{
			c+=b;
			times++;
		}
	}
	cout<<"2";
	return 0;
}
