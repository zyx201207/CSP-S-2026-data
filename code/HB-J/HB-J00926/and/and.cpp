#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];

bool cmp(ll p,ll q){
    return p>q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll maxx=5e9;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==maxx) i++;
			if(a[j]<maxx){
				maxx=a[j];
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}
