//GZ-J00178 观山湖中学 陈辰 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int a[N];
char s[N];
void solve(){
	int n,l=1,r,ans=0,rn=0,ln=0;
	cin >>n;
	r=n;
	for (int i = 1;i <= n;i++){
		cin >> a[i]>>s[i];
	} 
	while(l<r){
		if (s[l]!=s[r]){
			ans+=min(a[l]-ln,a[r]-rn);
		}
		if (a[l]-ln>a[r]-rn){
				ln+=a[r]-rn;
				r--;
				rn=0;
			}
			else if (a[l]-ln==a[r]-rn){
				l++,r++;
				ln=rn=0;
			}
			else{
				rn+=a[l]-ln;
				l++;
				ln=0;
			}
	}
	cout <<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin >>T;
	while(T--){
		solve();
	}
	return 0;
}
