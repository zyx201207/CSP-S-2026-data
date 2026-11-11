#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans=0;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=n-1,r=n;
	long long k=1;
	while(l){
		if(l==r){
			k=1;
			l--;
		}
		if(a[r]-a[l]>m&&r>l){
			m=m+(r-l-1)*(a[r]-a[r-1]);
			r--;
			k--;
		}else{
			m=m-(a[r]-a[l]);
			l--;
			k++;
			ans=max(k,ans);
		}
	}
	cout<<ans; 
	return 0;
} 
