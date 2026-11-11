//string
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N=1e5+5,M=5*N,K=5000;
ll n,ans,l,r,lpos,rpos,k;
int a[M];
char c[M];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	l=1;r=n;
	lpos=a[1];
	rpos=a[n];
	while(l<=r){
		k=min(lpos,rpos);
		if(c[l]!=c[r]) {
			ans+=k;
		}
		lpos-=k;
		rpos-=k;
		if(lpos==0) {
			l++;
			lpos=a[l];
		}
		if(rpos==0) {
			r--;
			rpos=a[r];
		}
	}
	cout << ans;
	return 0;
}
