#include<bits/stdc++.h>
using namespace std;
const int MAXN=210000;//请确定数组大小!!!
int d[MAXN],n,m;
int cnt=1;
int check(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((d[i]&x)==x)ans++;
	}
	return (ans>=m);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);//请确认文件名（尤其是输出）
	//不要开头就写xxx3.out，有可能覆盖文件
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	int l=0,r=(1<<30)+10,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}

