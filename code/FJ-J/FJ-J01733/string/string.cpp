#include<bits/stdc++.h>
using namespace std;
int ans=0;
char c[200005],res;
string s;
int a[200005],rest=0;
/*void change(int n)
{
	int l=1,r=n;
	while(l<=r) 
	{
		if(a[l]!=a[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				for(int i=r+1;i>=l+2;i--)
				{
					c[i]=c[i-1];
					a[i]=a[i-1];
				}
				a[l+1]=a[l]-a[r];
				c[l+1]=c[l];
			}
		}	
	}
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c ",&a[i],&c[i]);
	//int l=1,r=n;
	//change(n);*/
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	int l=0,r=s.size()-1;//a[i]*n,可以对15个 ，60分 
	while(l<=r)
	{
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	printf("%d\n",ans);
	return 0;
}
