#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+1;
ll n,ans,a[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[l]=a[r]=0;
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
