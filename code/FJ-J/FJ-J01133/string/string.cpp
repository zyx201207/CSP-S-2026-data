#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[210000],b[210000];
char s[210000],s1[210000];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);//请确认文件名（尤其是输出）
	//不要开头就写xxx3.out，有可能覆盖文件
	int n;
	cin>>n;
	int summ=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		b[n-i+1]=a[i];
		s1[n-i+1]=s[i];
		summ+=a[i];
	} 
	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	for(int i=2;i<=n;i++)b[i]+=b[i-1];
	int l=1,r=1,las=0;
	int ans=0;
	while(las<summ/2)
	{
		if(s[l]!=s1[r])
		{
			if(a[l]<b[r])
			{
				ans+=a[l]-las;
				las=a[l];
				l++;
			}
			else
			{
				ans+=b[r]-las;
				las=b[r];
				r++;
			}
		}
		else
		{
			las=min(a[l],b[r]);
			if(a[l]<b[r])l++;
			else r++;
		}
	}
	cout<<ans;
	return 0;
}



