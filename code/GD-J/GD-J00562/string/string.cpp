#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int cnt;
		cnt=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=cnt;
		    a[l]-=cnt;
		    a[r]-=cnt;
		if(a[l]==0){
			l++;
		}else{
			r--;
		}
		}else{
			a[l]-=cnt;
		    a[r]-=cnt;
		if(a[l]==0){
			l++;
		}else{
			r--;
		}
		}
	}
	cout<<ans;
	return 0;
} /*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
