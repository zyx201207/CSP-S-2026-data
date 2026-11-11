//GZ-J00565 ¡∫∫È»Ò 
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),greater<int>());
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		int res=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			res&=a[j];
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
