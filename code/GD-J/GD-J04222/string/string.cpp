#include<bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
int n,a[114514*2],p1,p2,ans;
char c[114514*2];
void input(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	p1=1,p2=n;
}
void solve(){
	input();
	while(p1<p2){
		if(a[p1]>a[p2]) ans+=(c[p1]==c[p2] ? 0:a[p2]),a[p1]-=a[p2--];
		elif(a[p1]<a[p2]) ans+=(c[p1]==c[p2] ? 0:a[p1]),a[p2]-=a[p1++];
		else ans+=(c[p1]==c[p2] ? 0:a[p2]),p1++,p2--;
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}//Trick||Treat!
