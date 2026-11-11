#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,b[N],ans;
bool v[N];
struct node{
	int x,y;
}a[N];
bool cmp(node n1,node n2){
	if(n1.y==n2.y)
		return n1.x>n2.x;
	return n1.y>n2.y;
}
bool cmp2(node n1,node n2){
	return n1.x>n2.x;
}
int count(int x){
	int res=0;
	while(x){
		res+=(x&1);
		x>>=1;
	}
	return res;
}
void dfs(int p,int num){
	if(p>m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=1;
			dfs(p+1,num&a[i].x);
			v[i]=0;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=count(a[i].x);
	}
	if(m==1){
		sort(a+1,a+n+1,cmp2);
		cout<<a[1].x<<'\n';
	}
	else if(pow(n,m)<5e7){
		for(int i=1;i<=n;i++){
			v[i]=1;
			dfs(2,a[i].x);
			v[i]=0;
		}
		cout<<ans<<'\n';
	}
	else{
		sort(a+1,a+n+1,cmp);
		ans=a[1].x;
		for(int i=1;i<=m;i++)
			ans&=a[i].x;
		cout<<ans<<'\n';
	}
	return 0;
}
