#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r,a[200005],cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n,l=1;
	while(l<r){
		cnt=min(a[l],a[r]);
		a[l]-=cnt;
		a[r]-=cnt;
		if(c[l]!=c[r]){
			ans+=cnt;
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}cout<<ans;
	return 0;
}
