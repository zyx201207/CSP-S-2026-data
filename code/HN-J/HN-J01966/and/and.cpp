#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],mx=-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i] && a[j]>mx) mx=a[i] && a[j];
		    }
	    }
	    cout<<mx;
	}
	int b=3 and 12;
	cout<<b;
	return 0;
}

