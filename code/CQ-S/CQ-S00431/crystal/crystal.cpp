#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+5;
int a[N];
int j;
int ans;
int he;
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	j=1;ans=1;
	for(int i=2;i<=n;i++){
		he=he+(i-j)*(a[i]-a[i-1]);
		while(he>m){
			he-=(a[i]-a[j]);j++;
		}
		ans=max(ans,(i-j+1));
	}
	cout<<ans;
	return 0;
} 
