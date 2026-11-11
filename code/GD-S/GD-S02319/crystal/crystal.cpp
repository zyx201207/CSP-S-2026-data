#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],d[N];
long long m,ans;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]+d[i-1];
	}
	for(int i=1;i<=n;i++){
		long long l=0,r=i;
		while(l<=r-1){
			long long mid=(l+r)/2;
			long long td=a[i]*(r-l-1)-(d[r-1]-d[l]);
			if(td<=m){
				ans=max(ans,r-l);
				r=mid;
			}
			else {
				l=mid;
			}
		}
	}
	cout<<ans;
}
