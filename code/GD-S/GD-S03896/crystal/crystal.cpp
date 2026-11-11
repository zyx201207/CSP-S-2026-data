#include<bits/stdc++.h>
using namespace std;
const long long maxm=50000000005;
long long a[maxm];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0;
	long long cost=0;
	int ans=1;
	for(int j=0;j<n;j++){
		if(j>0)cost+=(long long)(j-l)*(a[j]-a[j-1]);
		while(cost>m){
			cost -= a[j]-a[l];
			l++;
		}
		if(j-l+1>ans)ans=j-l+1;
	}
	cout<<ans;
	return 0;
}
