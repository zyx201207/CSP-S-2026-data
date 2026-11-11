#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[500005],m,maxn=0;
ll sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){//O(n log n)
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){//O(n)
		sum+=(i-1)*(a[i]-a[i-1]);
		if(sum>m){
			cout<<i-1;
			break;
		}
	}
	return 0;
 }
