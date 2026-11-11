#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int a[N];
char s[N];
//int cnt[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
//		cnt[i]=cnt[i-1]+a[i];
	}
//	int mid=cnt[n];
	int l=1,r=n;
	int ans=0;
	while(l<=r)
	{
		if(a[l]==a[r])
		{
			if(s[l]!=s[r]) ans+=a[l];
			l++;
			r--;
		}
		if(a[l]<a[r])
		{
			if(s[l]!=s[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[l]>a[r])
		{
			if(s[l]!=s[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
//	while(l<=r)
//	{
//		if(a[l]==a[r])
//		{
//			if(s[l]!=s[r])
//			{
//				ans+=a[l];
//				cout<<"当前组："<<l<<"+"<<r<<" 数量："<<a[l]<<"+"<<a[r]<<" 元素："<<s[l]<<"+"<<s[r]<<endl;
//				cout<<"当前答案："<<ans<<endl;
//				cout<<"当前类型：l=r"<<endl; 
//			}
//			l++;
//			r--;
//			continue;
//		}
//		if(a[l]<a[r])
//		{
//			if(s[l]!=s[r])
//			{
//				ans+=a[l];
//				cout<<"当前组："<<l<<"+"<<r<<" 数量："<<a[l]<<"+"<<a[r]<<" 元素："<<s[l]<<"+"<<s[r]<<endl;
//				cout<<"当前答案："<<ans<<endl;
//				cout<<"当前类型：l<r"<<endl;
//			} 
//			a[r]-=a[l];
//			l++;
//			cout<<"改动后的l与r："<<l<<" "<<r<<endl;
//			continue;
//		}
//		if(a[l]>a[r])
//		{
//			if(s[l]!=s[r])
//			{
//				ans+=a[r]; 
//				cout<<"当前组："<<l<<"+"<<r<<" 数量："<<a[l]<<"+"<<a[r]<<" 元素："<<s[l]<<"+"<<s[r]<<endl;
//				cout<<"当前答案："<<ans<<endl;
//				cout<<"当前类型：l>r"<<endl;
//			}
//			a[l]-=a[r];
//			r--;
//			continue;
//		}
//	}
//	cout<<ans;
	return 0; 
}
