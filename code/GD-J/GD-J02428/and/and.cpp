#include<bits/stdc++.h>
using namespace std;
#define int long long
struct xx{
	int x,num;
}a[200010];
int n,m,x,ma=-1;
bool cmp(xx a,xx b){
	if(a.x==b.x) return a.num>b.num;
	return a.x>b.x;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		ma=max(ma,x);
		a[i].num=x;
		while(x!=0){
			a[i].x+=x%2;
			x/=2;
		}
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1].num;
	for(int i=2;i<=m;i++) ans&=a[i].num;
	cout<<ans;
}
