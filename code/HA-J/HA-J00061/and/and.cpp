#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans=0,ma=-1000;
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i]&a[i+1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(m==1){
			cout<<a[n];
			return 0;
		}
		else cout<<1;
	}
	return 0;
}
//Trick||Treat!
/*


4 2
3 15 12 12



*/
