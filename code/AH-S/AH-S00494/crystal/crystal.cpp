#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,ans;
long long m,a[500005],s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long l=1,r=1;
	while(l<=n&&r<=n){
		while(r<n){
			if((a[r+1]-a[r])*(r-l+1)+s<=m){
				s+=(a[r+1]-a[r])*(r-l+1);
				r++;
			}else break;
		}
		ans=max(ans,(int)(r-l+1));
		s-=a[r]-a[l];
		l++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
