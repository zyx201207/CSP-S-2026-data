#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans[100],c=1;
struct node{
	int s;
	char c;
}a[200005];
struct node1{
	int x,y;
};
void add(int p){
	int x[100]={0},u=0;
	while(p){
		u++;
		x[u]=p%10;
		p/=10;
	}
	for(int i=1;i<=max(u,c);i++){
		ans[i]+=x[i];
		if(ans[i]>=10){
			ans[i+1]++;
			ans[i]-=10;
		}
	}
	c=max(c,u);
	if(ans[c+1]>0)c++;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].c;
	node1 l={1,a[1].s},r={n,a[n].s};
	while(l.x<r.x){
		if(l.y>r.y){
			if(a[l.x].c!=a[r.x].c)add(r.y);
			l.y-=r.y;
			r.x--;
			r.y=a[r.x].s;
		}else{
			if(a[l.x].c!=a[r.x].c)add(l.y);
			r.y-=l.y;
			l.x++;
			l.y=a[l.x].s;
		}
	}
	for(int i=c;i>=1;i--)cout<<ans[i];
	return 0;
} 
