#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long s=0,l=1,ans=0;
	for(int r=1;r<=n;r++){
		s=s+(a[r]-a[r-1])*(r-l);
		while(s>m){
			s-=(a[r]-a[l]);
			l++;
			ans=max(ans,r-l+1);
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

