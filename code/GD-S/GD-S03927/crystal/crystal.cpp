#include<bits/stdc++.h>
#define intt long long 
using namespace std;
intt n,m;
intt a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(intt i=1;i<=n;i++){
		cin>>a[i];	
	}
//	for(int i=2;i<=n;i++){
//		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
//	}
	sort(a+1,a+1+n);
	intt ans=0,l=1,r=1,s=0,len=1;
	while((l<=r && l<=n)){
		if(s<=m && r<n){
			ans=max(len,ans);
			r++;
			s+=(a[r]-a[r-1])*len;
			len++;
		}else{
			l++;
			s-=(a[r]-a[l-1]);
			len--;
		}
//		cout<<l<<' '<<r<<' '<<s<<'\n';
	}
	cout<<ans;
	return 0;
} 
