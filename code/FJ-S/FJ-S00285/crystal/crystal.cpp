#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=1;
long long m,a[N],res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=2;i<=n;i++){
		res+=(long long)(i-l)*(a[i]-a[i-1]);
		while(res>m&&l<i){
			res-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
