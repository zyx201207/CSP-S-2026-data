#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N = 5e5+5;
int n;
ll sum = 0,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	fr(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int j = 1,ans = 1;
	fr(i,2,n){ 	
		sum = sum+(i-j)*(a[i]-a[i-1]);
		while(sum>m&&j<=i){
			sum = sum-(a[i]-a[j]);
			j++;
		}
		ans = max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
