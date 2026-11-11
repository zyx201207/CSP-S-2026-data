#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
struct inf{
	ll sum;
	char a;
}g[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>g[i].sum>>g[i].a;
	}
	ll l=1,r=n;
	while(l<=r){
		if(g[l].a!=g[r].a){
			ans+=min(g[l].sum,g[r].sum);
			if(g[l].sum>g[r].sum){
				g[l].sum-=g[r].sum;
				r--;
			}
			else if(g[l].sum<g[r].sum){
				g[r].sum-=g[l].sum;
				l++;
			}
			else{
				l++;r--;
			}
		}
		else{
			if(g[l].sum>g[r].sum){
				g[l].sum-=g[r].sum;
				r--;
			}
			else if(g[l].sum<g[r].sum){
				g[r].sum-=g[l].sum;
				l++;
			}
			else{
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
} // 100% AC
/*
3
2 a
2 b
1 c
*/
