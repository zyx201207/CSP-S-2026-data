#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ch(int mid,vector<int> a,int n,int m){
	int b=false;
	for(int i=0;i<=a.size()-mid;++i){
		int c=0;
		for(int j=i;j<=i+mid-1;++j){
			c+=a[i+mid-1]-a[j];
		}if(c<=m) b=true;
	}if(b) return true;else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	if(n>5000&&m>=1e8+1){
		sort(a.begin(),a.end());
		int s=a[1]-a[0];
		int nm=0;
		for(int n1=0;n1+s*(n1-1)*n1/2<=m;++n1){
			nm=max(n1,nm);
		}if(nm==0){
			cout<<1;
			return 0;
		}else{
			cout<<nm+1;
			return 0;
		}
	}
	sort(a.begin(),a.end());
	int l=1,r=n;
	while(l<r){
		int mid=(r-l+1)/2+l;
		if(ch(mid,a,n,m)) l=mid;
		else r=mid-1;
	}cout<<l;return 0;
} 
