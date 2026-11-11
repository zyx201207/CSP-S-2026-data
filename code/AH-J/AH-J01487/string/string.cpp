#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=0,r=n-1,sl=0,sr=a[n-1]-1;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			int y=min(sr+1,a[l]-sl);
			sr-=y;
			sl+=y;
			if(sl>=a[l])
			{
				l++;
				sl=0;
			}
			if(sr<0)
			{
				r--;
				sr=a[r]-1;
			}
		}
		else
		{
			ans++;
			sl++;
			if(sl>=a[l])
			{
				l++;
				sl=0;
			}
			sr--;
			if(sr<0)
			{
				r--;
				sr=a[r]-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
