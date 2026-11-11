#include<bits/stdc++.h>
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e5+10;
void _freopen(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
int a[N];
char b[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}	
	int ans=0;
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				b[l]=b[r];
				l++;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				b[r]=b[l];
				r--;			
			}
		}
		//cout<<ans<<endl;
	} 
	cout<<ans;
}
signed main(){
	No TLE
	_freopen();
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

