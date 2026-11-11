#include <bits/stdc++.h>
using namespace std;
long long n, cnt[200005], l, r, ans, f;
struct node{
	int a, cnt; string b;
}d[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>d[i].a>>d[i].b;
		if(d[i].b!=d[i-1].b) f=1;
	}
	if(!f){
		cout<<0;
		return 0;
	}
	l=1, r=n;
	while(l<r){
		if(d[l].b!=d[r].b){
			if(d[l].a<d[r].a){
				ans+=d[l].cnt;
				d[r].a-=d[l].a;
				l++;
			}
			else if(d[l].a>d[r].a){
				ans+=d[r].cnt;
				d[l].a-=d[r].a;
				r--;
			}
			else{
				ans+=d[r].a;
				l++, r--;
			}
		}
		else{
			if(d[l].a<d[r].a){
				d[r].a-=d[l].a;
				l++;
			}
			if(d[l].a>d[r].a){
				d[l].a-=d[r].a;
				r++;
			}
			if(d[l].a==d[r].a){
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
