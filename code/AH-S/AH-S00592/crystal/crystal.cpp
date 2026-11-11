#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+10;

int n,m;
int a[N];
int s[N];

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1]+a[i];
	}
	
	int l=1,r=1;
	
	int ans=0;
	
	while(r<=n){
		int sum=s[r]-s[l-1];
		int ach=(r-l+1)*a[r];
		
		while(ach>sum+m){
			l++;
			sum=s[r]-s[l-1];
			ach=(r-l+1)*a[r];
		}
		ans=max(ans,r-l+1);
		
		r++;
	}
	cout<<ans;
	
	return 0;
}
/*
5 5
1 2 4 8 9
*/
