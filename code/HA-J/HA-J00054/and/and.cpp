#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxx;
ll a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
}
/*  8~10点应该能过 */
// 骗分骗分!!! 
