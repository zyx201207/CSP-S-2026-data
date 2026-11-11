#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		if(a[l]>a[r])
			a[l]-=a[r],a[r]=0,r--;
		else if(a[r]>a[l])
			a[r]-=a[l],a[l]=0,l++;
		else
			a[l]=a[r]=0,l++,r--;
	}
	cout<<ans;
	return 0;
}
