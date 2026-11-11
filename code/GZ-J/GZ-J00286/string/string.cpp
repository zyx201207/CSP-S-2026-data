//GZ-J00286  谢雨辰  遵义市新蒲中学 
#include <bits/stdc++.h>
using namespace std;
char m[199999999];
struct STR
{
	int number;
	char shu;
}a[199999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=1,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].number>>a[i].shu;
		for(int j=1;j<=a[i].number;j++)
		{
			m[len]=a[i].shu;
			len++;
		}
	}
		int l=1,r=len-1;
		while(l<=r)
		{
			if(m[l]!=m[r])
			{
				sum++;
			}
			l++;
			r--;
		}
	cout<<sum;
	return 0;
}

