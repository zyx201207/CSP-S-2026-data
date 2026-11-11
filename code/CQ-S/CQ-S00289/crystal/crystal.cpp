#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[3000005];
long long l=1,r=0;
long long v=0;
long long ans=0;
bool cmp(long long x,long long y){
	return x<y;
}
long long q[3000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;n>=i;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	while(r<=n){
		if(r<l){
			++r;
			q[r]=a[r];
			continue;
		}
		else {
			long long sum=q[r];
			r++;
			v+=(r-l)*(a[r]-sum);
			q[r]=a[r];
			while(v>m){
				v-=(q[r]-q[l]);
				l++;
			}
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
