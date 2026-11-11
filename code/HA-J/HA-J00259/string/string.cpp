#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll n,a[N],sum,ans=0; char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(b[l]!=b[r]){
			if(a[r]<a[l]){
				a[l]-=a[r];ans+=a[r];
				r--;
			}else if(a[r]==a[l]){
				ans+=a[r];r--,l++;
			}else if(a[l]<a[r]){
				a[r]-=a[l];ans+=a[l];
				l++;
			}
		}else{
			if(a[r]<a[l]){
				a[l]-=a[r];
				r--;
			}else if(a[r]==a[l]){
				r--,l++;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

