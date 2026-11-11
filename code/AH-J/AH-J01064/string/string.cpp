#include<bits/stdc++.h>
using namespace std;
long long n,a[300000],l=1,r,sumn=0;
char c[300000];
void change(int x)
{
	if(x==1)
		sumn+=min(a[l],a[r]);
	if(a[l]>a[r])
	{
		a[l]-=a[r];
		r--;		
	}
	else
	{
		a[r]-=a[l];
		l++;		
	}
	//cout<<sumn<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<=r)
	{
		//cout<<l<<' '<<r<<endl;
		if(c[l]==c[r])
			if(a[l]==a[r])
			{	
				l++;
				r--;
			}
			else
				change(0);	
		else
			if(a[l]==a[r])
			{
				sumn+=a[l];
				l++;
				r--;				
			}
			else
				change(1);
		
	}
	cout<<sumn;
	return 0;
}
