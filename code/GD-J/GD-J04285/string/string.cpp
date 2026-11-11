#include<bits/stdc++.h>
using namespace std;
int n,a[200005],mid1,mid2,len,ans;
char c[200005],l[100010],r[100010];
string s;
int main(){
	freopen(string,r,stdin);
	freopen(string,w,stdout);
	cin>>n;//输入 
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i = 1;i<=n;i++)//合并 
	{
		for(int j = 1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	len=s.size();
	if(len%2==0)//找中间 
	{
		mid1=len/2-1;
		mid2=len/2;
		if(mid1!=mid2)ans++;
	}
	else {
		mid1=len/2;
		mid2=len/2;
	}
	for(int i = 0;i<mid1;i++)//string 转char,1项=1左右分开 
	{
		l[i+1]=s[i];
	}
	for(int i = mid2+1;i<=len;i++)//string 转char,1项=1左右分开 
	{
		r[i-mid2]=s[i];
	}
	len=mid1;
	for(int i = 1;i<=len;i++)
	{
		if(l[i]!=r[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
