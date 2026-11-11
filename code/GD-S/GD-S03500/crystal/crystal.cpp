#include<bits/stdc++.h>
using namespace std;
//¿ªlong long,freopen!!!
long long n,m,a[500005],ans,s[500005];
bool check(int l,int r){
	int need=s[r-1]-s[l-1];
	need=(r-l)*a[r]-need;
	if(need>m){
		return 0;
	}
	return 1;
} 
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
		long long an=1,k=m,l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		an=i-l+1;
//		cout<<l<<' '<<i<<endl;
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
} 
