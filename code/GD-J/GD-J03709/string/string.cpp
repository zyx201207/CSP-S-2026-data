#include<iostream>
using namespace std;
long long a[200005];
char c[200005];
long long len;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],len+=a[i];
	int left=1,right=n;
	for(int i=1;i<=len/2&&left<=right;)
	{
		if(a[left]>a[right])
		{
			a[left]-=a[right];
			if(c[left]!=c[right]) ans+=a[right];
			right--;
		}
		else
		{
			a[right]-=a[left];
			if(c[left]!=c[right]) ans+=a[left];
			left++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
