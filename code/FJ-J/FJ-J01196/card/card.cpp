#include<bits/stdc++.h>
#define int long long
using namespace std;
struct li{
	li(int _l=0,int _r=0){
		l=_l;
		r=_r;
	} 
	int l,r;
};
int a[500005];
int bt[300005];
vector<li> v;
vector<int> ll;
int cnt[300005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(bt[a[i]]==0) bt[a[i]]=i;
		else{
			v.push_back(li(bt[a[i]],i));
			ll.push_back(bt[a[i]]);
			bt[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			int t=lower_bound(ll.begin(),ll.end(),j)-ll.begin();
			if(ll[t]==j){
				j=v[t].r;
			}else{
				cnt[a[j++]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	
	return 0;
}
