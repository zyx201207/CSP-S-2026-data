#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 lll;
typedef long double ld;
mt19937 rnd(time(0));
const int N=5e5+1145;
int n;
ll m,a[N],qz[N];
ll ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		qz[i]=a[i]+qz[i-1];
		while(r>=l){
			int mid=(l+r)/2;
			if((ll)(i-mid+1)*a[i]-(qz[i]-qz[mid-1])<=m){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
//		cerr<<a[i]<<" "<<l<<"\n";
		ans=max((ll)i-l+1,ans);
	}
	cout<<ans<<'\n';
	return 0;
	
}
/*

5 2
-2 -2 -5 -5 -999

*/
