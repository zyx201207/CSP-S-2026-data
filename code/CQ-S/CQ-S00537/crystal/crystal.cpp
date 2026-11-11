#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,ans=1;
	long long now=0;
	for(int i=1;i<=n;i++){
		now+=a[i];
		while(l<i&&a[i]*(i-l+1)-now>m){
			now-=a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}