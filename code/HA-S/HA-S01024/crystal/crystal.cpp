#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}	
	int l=1,r=1,ans=0;
	while(r<=n&&l<=r){
		if(l+ans>n)break;
		while(m+a[r]-a[l-1]>=(a[r]-a[r-1])*(r-l+1)&&r<=n){
			r++;
		}
		if(m+a[r]-a[l-1]<(a[r]-a[r-1])*(r-l+1)){
			r--;	
		}
		ans=max(ans,r-l+1);
		l++;
		if(r<l)r=l;
	}
	cout<<ans;

	return 0;
}
