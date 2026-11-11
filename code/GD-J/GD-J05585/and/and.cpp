#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cc=0,ans=0,mx=0;
void brain(int i,int j)
{
	int l1,l2;
	cc=0,ans=0;
	for(int x=i,y=a[j];x>0&&y>0;x=x/2,y=y/2)
	{
		l1=x%2,l2=y%2;
		if(l1==1&&l2==1)
		{
			ans+=(long long)pow(2,cc);
		}
		cc++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n-m+1;j++)
    	{
    		ans=a[i];
    		for(int q=1;q<=m-1;q++)
    		{
    			brain(ans,j+q);
			}
    		mx=max(ans,mx);
		}
	}
	cout<<mx;
	return 0;
}
