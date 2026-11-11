#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,ans=1;
long long a[N];
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i,mid,pos;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				pos=mid;
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
}
