#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r,ans,mid;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<r){
		mid=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=mid;
		}
		a[l]-=mid;
		a[r]-=mid;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
