#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 7;

int _, n, ans;

struct mb{
	int x;
	char c;
}p[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(p[l].c!=p[r].c){
			if(p[l].x<p[r].x){
				ans+=p[l].x;
				p[r].x-=p[l].x;
				l++;
			}
			else{
				ans+=p[r].x;
				p[l].x-=p[r].x;
				r--;
			}
		}
		else{
			if(p[l].x<p[r].x){
				p[r].x-=p[l].x;
				l++;
			}
			else{
				p[l].x-=p[r].x;
				r--;
			}
		}
	}
	cout<<ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
	while(_--){
		solve();
	}
}
