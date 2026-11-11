#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=2e5+5;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[dd];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-1e9,cnt=0,x;
    for(int i=2;i<=n;i++){
		x=(a[i]||a[i-1]);
		if(x>maxx) maxx==x,cnt++;
		else{
			cnt=0;
		}
	}
	cout<<maxx<<endl;
	return 0;
}
