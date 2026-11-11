#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
bool t=0;
int a2=0,a1=0,a3=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
		cin>>a[i];
		if(a[i]>=4) t=1;
		if(a[i]==2) a2++;
		if(a[i]==1) a1++;
		if(a[i]==3) a3++;
	}
	if(t==0)
	{
		sort(a+1,a+n+1,cmp);
		if(a[m]>=2) cout<<a[m];
		else if(a[m]==1&&a2==0) cout<<1;
		else if(a2!=0&&a3+a2<m&&a3+a1<m) cout<<0;
		else if(a2!=0&&a3+a2>=m) cout<<2;
		else if(a2!=0&&a3+a1>=m) cout<<1;
		return 0;
	}//10
    if(m==1)
    {
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}//5
	if(m==2)
	{
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) maxn=max(maxn,(a[i]&a[j]));
		}
		cout<<maxn;
		return 0;
	}//15
	//15+5+10=30
	return 0;
}
