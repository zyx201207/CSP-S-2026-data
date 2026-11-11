#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans;
char c[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,r=n;
	for(long long i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
		}
		else {
			
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
				
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
				
			}
			else if(a[l]==a[r]){
			  ans+=a[r];
				l++;
				r--;
				
			}
		}
	}
	cout<<ans;
	return 0;
}