#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;

int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		if(n==1) cout<<a[1];
		else{
			int t=a[1];
			for(int i=2;i<=n;i++){
				t=t&a[i];
			}
			cout<<t;
		}
		return 0;
	}
	if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
