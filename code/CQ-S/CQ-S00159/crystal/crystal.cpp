#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500099];
int ans;
int check(int num)
{
	int cnt=0;
	for(int i=1;i<num;i++)
	{
		cnt+=a[i];
	}
	for(int i=num;i<=n;i++)
	{
		cnt-=a[i-num];
		cnt+=a[i];
//		cout<<"cnt: "<<cnt<<"jg: "<<a[i]*num-cnt<<endl;
		if(a[i]*num-cnt<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check(mid)==1)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l; 
}

