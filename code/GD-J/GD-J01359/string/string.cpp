#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans;char c[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	int l=1,r=n;
	for(int i=1;i<n;i++)
	{
		if(c[l]!=c[r]){
			if(a[l]>=a[r])
			{a[l]-=a[r],ans+=a[r],a[r]=0;
			r--;
			}
			else if(a[l]<a[r])
			{a[r]-=a[l],ans+=a[l],a[l]=0;
			l++;
			}
		}
		else {
			if(a[l]>=a[r])
			{a[l]-=a[r],a[r]=0;
			r--;
			}
			else if(a[l]<a[r])
			{a[r]-=a[l],a[l]=0;
			l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
