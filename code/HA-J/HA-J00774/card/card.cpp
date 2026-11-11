#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return

const ll N=5e5+50;
const ll M=3e5+50;
ll n,m,a[N],ans[M];
vector<ll>desk;
map<ll,ll>des;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	fr(i,1,n)	cin>>a[i];
	fr(i,1,n){
		desk.clear();des.clear();
		fr(j,i,n){
			if(des[a[j]]!=0){
				fr(k,des[a[j]],j-i)
					des[desk[k]]=0;
			}
			desk.push_back(a[j]);
			des[a[j]]=j-i+1;
		}
		fr(i,1,m)	if(des[i]!=0)	ans[i]++;
	}
	fr(i,1,m)	cout<<ans[i]<<" \n"[i==n];
	lwq 0;
}