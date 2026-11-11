#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int cnt[200010];
char c;
char a[200010];
int len;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		if(a[len]!=c)
		{
			a[++len]=c;
			cnt[len]=n;
		}
		else cnt[len]+=n;
	}
	for(int i=1,j=len;i<j;)
	{
		if(cnt[i]>cnt[j])
		{
			if(a[i]!=a[j])ans+=cnt[j];
			cnt[i]-=cnt[j];
			j--;
		}
		else 
		{
			if(a[i]!=a[j])ans+=cnt[i];
			cnt[j]-=cnt[i];
			i++;
		}
	}
	cout<<ans;
//	for(int i=1;i<=len;i++)
//		cout<<a[i].l<<' '<<a[i].c<<endl;
//	sum=sum/2+(sum%2);
//	int l=0,r=len;
//	while(l<r)
//	{
//		int mid=l+r>>1;
//		if(cnt[mid].r<sum)l=mid+1;
//		else r=mid;
//	}
	return 0;
}