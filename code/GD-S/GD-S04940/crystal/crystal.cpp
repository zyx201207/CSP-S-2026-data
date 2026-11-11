#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int ans=0;
int a[500005];
void binery(int size,int tot)
{
	int r=size/2;
	int l=size/2+1;
	int ori=size;
	if(size%2==1) l=size/2+1;
	if(size%2==0) l=size/2;
	int origin=a[l];
	for(int i=1; i<=size; i++)
	{
		a[i]=a[i]-origin;
//		cout<<a[i]<<" ";
	}
	
	for(int i=1; i<=tot; i++)
	{
		int pas=0-a[l+1];
//		cout<<pas<<"/";
		if(a[l-1]<pas)
		{
			int mini=a[l-1];
			i+=mini;
			l-=1;
//			cout<<"turn left ";
			ans++;
		}
		if(a[l-1]>pas)
		{
			int mini=pas;
			i+=mini;
			l+=1;
//			cout<<"turn right ";
			ans++;
		}
		if(a[l-1]==pas)
		{
			ans++;
		}
		
	}
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) 
	{
		cin>>a[i];
//		v.push_back(a);
	}
	sort(a+1,a+n+1,greater<>());
//	for(int i=1; i<=n; i++) cout<<a[i];
	binery(n,m);
	cout<<ans;
	return 0;
}
