#include<bits/stdc++.h>
using namespace std;
#define int long long
int T=1,n,ans=0;
int a[200010];
char c[200010];
string s;

void solve(){
	cin>>n;
	int L=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+= a[i];
	}
	if(L<=2e5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+= c[i];
			}
		}
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[L-i-1])ans++;
		}
		cout<<ans;
	}else{
		int l=1,r=n;
		while(l<=r){
			if(a[l]<a[r]){
				if(c[l]!=c[r])ans+= a[l];
				a[r]-= a[l];
				l++;
			}else if(a[l]>a[r]){
				if(c[l]!=c[r])ans+= a[r];
				a[l]-= a[r];
				r--;
			}else {
				if(c[l]!=c[r])ans+= a[l];
				l++;
				r--;
			}
		}
		cout<<ans;
	}
} 

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
