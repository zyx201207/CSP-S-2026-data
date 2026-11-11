#include<bits/stdc++.h>
using namespace std;
int n,m;
long long  a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<=(2<<n)-1;i++){
		long long s = (2<<21)-1,ans = 0;
		for(int j = 0;j<n;j++){
			if(((i>>j) & 1 ) == 1){
				ans++;
				s &= a[j+1];
			}
		}
		if(ans == m){
			maxx = max(s,maxx);
		}
	}
	cout<<maxx;
} 
