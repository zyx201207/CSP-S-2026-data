#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9;
struct node{
	int x;
	char c;
}a[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(a[l].c==a[r].c){
			int mn=min(a[l].x,a[r].x);
			a[l].x-=mn;
			a[r].x-=mn;
			if(!a[l].x){
				l++;
			}
			if(!a[r].x){
				r--;
			}
		}else{
			int mn=min(a[l].x,a[r].x);
			a[l].x-=mn;
			a[r].x-=mn;
			ans+=mn;
			if(!a[l].x){
				l++;
			}
			if(!a[r].x){
				r--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
