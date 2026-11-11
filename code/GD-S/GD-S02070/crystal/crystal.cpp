#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],sm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	sm[0]=0;
	for(int i=1;i<=n;i++){
		sm[i]=a[i]+sm[i-1];
	}
	long long l=1,r=2,ans=1;
	long long s=0;
	while(r<=n){
		s=a[r]*(r-l+1)-(sm[r]-sm[l-1]);
		while(s>m){
			l++;
			s=a[r]*(r-l+1)-(sm[r]-sm[l-1]);
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
