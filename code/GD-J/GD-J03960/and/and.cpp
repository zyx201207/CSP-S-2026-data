#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans=-1;
long long a[2000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		long long x;
		bool fir=true;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(fir){
					x=a[j];
					fir=false;
					continue;
				}
				x=x&a[j];
			}
		}
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
