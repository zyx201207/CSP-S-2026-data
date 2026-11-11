#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
bool check(int l,int r){
	int cntk=0;
	for(int i=l;i<=r;i++){
		cntk+=(a[r]-a[i]);
	}
	if(cntk<=m){
		return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+maxx;j<=n;j++){
			if(check(i,j)){
				maxx=max(maxx,j-i+1);
			}
		}
	}
	cout<<maxx;
    return 0;
}