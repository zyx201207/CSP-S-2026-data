#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=2e5+5;
struct node{
	int cf;
	char ch;
};
int n;
int ans;
node a[MAXN];
int l,r;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;r=n;
	for(int i=1;i<=n;i++) cin>>a[i].cf>>a[i].ch;
	while(l!=r){
		if(a[l].ch!=a[r].ch) ans+=min(a[l].cf,a[r].cf);
		a[l].cf-=min(a[l].cf,a[r].cf);
		a[r].cf-=min(a[l].cf,a[r].cf);
		if(a[l].cf==0) l++;
		if(a[r].cf==0) r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
