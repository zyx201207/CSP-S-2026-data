#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m;
int a[500001];
pair<bool,int> js[500001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)
		cin>>a[i];
	rep(i,1,m){
		int cnt=0;
		rep(j,1,n){
			rep(k,j,n){
				if(js[a[k]].fi){
					rep(l,js[a[k]].se+1,k-1)
						js[a[l]].fi=false;
				}
				js[a[k]].fi=true,js[a[k]].se=k;
			}
			if(js[i].fi)
				cnt++;
			rep(k,j,n)
				js[a[k]].fi=false,js[a[k]].se=0;
		}
		cout<<cnt<<" ";
	}
	return 0;
}
