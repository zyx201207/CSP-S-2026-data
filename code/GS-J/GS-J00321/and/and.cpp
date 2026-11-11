#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    ll maxx=0;
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
//    for(int i=1;i<=n;i++){
//    	ll r=0;
//    	for(int j=1;j<=m;j++)
//    		r=r&a[j];
//		maxx=max(maxx,r);
//	}
//	cout<<maxx;
	if(m==1){
		for(int i=1;i<=n;i++){ll x=a[i];maxx=max(maxx,x);}
		cout<<maxx;
	}else if(m==n){
		ll r=a[1];
		for(int i=1;i<=n;i++){
			r&=a[i];
		}
		cout<<r;
	}
    return 0;
}
