#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],sum,maxx;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(maxx<=500){
		string s="#";
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
			x+=a[i];
		}
		int ans=0;
		for(int i=1,j=s.size()-1;i<=j;i++,j--){
			if(s[i]!=s[j]) ans++;
		}
		cout << ans; 
		return 0;
	}
	return 0;
}
