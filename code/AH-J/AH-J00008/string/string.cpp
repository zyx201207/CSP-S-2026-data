#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
ll n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;vl a(n+1);vector<char> c(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r){
		if(c[l]==c[r]&&a[l]==a[r]) l++,r--;
		else if(c[l]==c[r]&&a[l]!=a[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else if(c[l]!=c[r]&&a[l]==a[r]){
			cnt+=a[l];
			l++,r--;
		}else if(c[l]!=c[r]&&a[l]!=a[r]){
			if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
