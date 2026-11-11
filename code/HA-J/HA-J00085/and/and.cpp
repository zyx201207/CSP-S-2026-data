#include<bits/stdc++.h>
using namespace std;
int n,m;
struct pos{
	int v,x;
}a[200005];
bool operator < (pos x,pos y){
	return x.x<y.x;
}
int b[35],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		for(int j=0;j<=31;j++){
			if((a[i].v&(1<<j))){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=31;j++){
			if(b[j]>=m){
				a[i].x+=(1<<j)&a[i].v;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m;i++){
		for(int j=0;j<=31;j++){
			if(a[i].x&(1<<j)){
				b[j]--;
			}
		}
	}
	for(int i=0;i<=31;i++){
		if(b[i]==m){
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
