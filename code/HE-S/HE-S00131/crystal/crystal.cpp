#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans=1,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long tmp=a[2]-a[1],tans=1,l=1,r=2;
	for(int i=2;i<=n;i++){
		while(tmp>m){
			tmp-=(a[i]-a[l]);
			l++;
		}
		ans=max(i-l+1,ans);
		r++;
		tmp+=(a[r]-a[i])*(r-l);
	} 
	cout<<ans;
	return 0;//ccf please let me ac
}
