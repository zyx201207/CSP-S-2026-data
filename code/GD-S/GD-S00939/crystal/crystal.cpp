#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1,v=0,ans=0;
	while(r<n){
		r++;
		v+=(a[r]-a[r-1])*(r-l);
		while(v>m){
			v-=a[r]-a[l];  
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0; 
} 
