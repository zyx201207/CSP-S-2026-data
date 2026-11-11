#include <bits/stdc++.h>
using namespace std;
struct xi{
	char c;
	long long num;
}a[200005];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	long long l=1,r=n, ans=0, cnt=0;
	for(int i=1;true;i++)
	{
		if(l>r)break;
		if(l==r)
		{
			ans*=2;
			ans=ans+sum-2*cnt;
			break;
		}
		if(a[l].num<a[r].num)
		{
			cnt+=a[l].num;
			a[r].num-=a[l].num;
			if(a[l].c==a[r].c)ans+=a[l].num;
			l++;
		}
		else if(a[l].num>a[r].num)
		{
			cnt+=a[r].num;
			a[l].num-=a[r].num;
			if(a[r].c==a[l].c)ans+=a[r].num;
			r--;
		}
		else{
			cnt+=a[r].num;
			if(a[r].c==a[l].c)ans+=a[r].num;
			r--;
			l++;
		}
	}
	cout<<(sum-ans)/2;
	return 0;
}
