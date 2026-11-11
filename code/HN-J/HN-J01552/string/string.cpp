#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(1){
		if(a[l]==a[r]&&a[l]!=0){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++,r--;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		if(l>=r){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
