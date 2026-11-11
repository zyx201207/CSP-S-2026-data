#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,ans,l,r;
char c[N],d;
string s[N];
int a[N];
bool flag=1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i==1) d=c[i];
		if(d!=c[i]) flag=0;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	l=1,r=n;
	if(n&1){
		while(l!=r){
			if(c[l]!=c[r]&&a[l]>=a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
				if(a[l]==0) l++;
			}else if(c[l]!=c[r]&&a[r]>=a[l]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
				if(a[r]==0) r--;
			}else{
				l++,r--;
			}
		}
	}else{
		while(l<=r){
			if(c[l]!=c[r]&&a[l]>=a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
				if(a[l]==0) l++;
			}else if(c[l]!=c[r]&&a[r]>=a[l]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
				if(a[r]==0) r--;
			}else{
				l++,r--;
			}
		}
	}
	if(a[l]) a[l]/=2;
	if(a[r]) a[r]/=2;
	cout<<ans+a[l]+a[r];
	return 0;
}
