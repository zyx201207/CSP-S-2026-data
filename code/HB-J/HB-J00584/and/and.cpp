#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m,a[N],b[N],ans=0;
void f(int x,int y,int cnt){
	if(y==m){
		if(cnt>ans) ans=cnt;
		return;
	}
	if(x==n) return;
	if(cnt==0) f(x+1,y+1,a[x]);
	else f(x+1,y+1,cnt&a[x]);
	f(x+1,y,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	f(0,0,0);
	cout<<ans;
	return 0;
}
