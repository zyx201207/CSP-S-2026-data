#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,a[N];
int MAXNUM=INT_MIN;
int main(){
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		MAXNUM=max(MAXNUM,a[i]);
	}
	for (int i=MAXNUM;i>=0;i--){
		//cerr<<i<<'\n';
		int cnt=0;
		for (int j=1;j<=n;j++){
			if ((i & a[j])==i){
				cnt++;
			}
		}
		if (cnt>=m){
			cout<<i;
			return 0;
		}
	}
}
