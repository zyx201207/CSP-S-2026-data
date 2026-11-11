#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++,r--;
				continue;
			}
			ans+=a[l];
			l++,r--;
		}
		else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
				continue;
			}
			a[r]-=a[l];
			ans+=a[l];
			l++;
		}
		else{
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
				continue;
			} 
			a[l]-=a[r];
			ans+=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
