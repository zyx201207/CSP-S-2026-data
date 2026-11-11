#include<bits/stdc++.h>
using namespace std;
int n,l,r,a[200010];
char c[200010];
long long lsum,rsum,sum,gsum;
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	l=1,r=n,lsum=a[l],rsum=a[r];
	while(lsum+rsum<=sum){
		int small=(a[l]<a[r]?l:r),big=l+r-small;
		if(c[l]!=c[r]){
			gsum+=a[small];
		}
		if(lsum<rsum)l++,flag=1;
		else r--,flag=0;
		a[big]-=a[small];
		if(flag)lsum+=a[l];
		else rsum+=a[r];
	}
	cout<<gsum;
	return 0;
}
