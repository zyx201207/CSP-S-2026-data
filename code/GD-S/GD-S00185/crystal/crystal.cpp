#include<bits/stdc++.h>
#define int long long
using namespace std;
const int q=5e5+5;
int n,m,a[q];
bool check(int k){
	int w=m;
	for(int i=1;i<k;i++){
		w-=a[k]-a[i];
	}
	if(w>=0) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		if(n==1){
			cout<<1;
			return 0;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			if(!check(i)){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}
	else{
		int i=sqrt(2*m);
		while(i*(i+1)/2<=m) ++i;
		cout<<i;
	}
	return 0;
}
