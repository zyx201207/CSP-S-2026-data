//GZ-J00565 ¡∫∫È»Ò 
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<char>b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]==a[r]){
			l++;
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
