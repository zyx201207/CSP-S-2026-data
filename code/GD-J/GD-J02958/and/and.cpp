#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int temp;
	int pos=0;
}a[N];
int n,m;
int maxx;
int ans;
void dfs(int x,int k){
	if(k==m){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=x+1;i<=n;i++){
		int cnt=ans;
		ans&=a[i].temp;
		dfs(i,k+1);
		ans=cnt;
	}
}
bool cmp(node x,node y){
	return x.temp>y.temp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].temp;
	}
	if(m==n){
		int p;
		for(int i=1;i<=n;i++){
			p&=a[i].temp;
		}
		cout<<p<<endl;
		return 0;
	}
	int flag=1;
	for(int i=1;i<n;i++){
		if(a[i].temp!=a[i+1].temp){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<a[1].temp<<endl;
		return 0;
	}
	flag=1;
	for(int i=1;i<=n;i++){
		if(a[i].temp>=4){
			flag=0;
			break;
		}
	}
	if(flag){
		sort(a+1,a+1+n,cmp);
		int pans=a[1].temp;
		for(int i=2;i<=m;i++){
			pans&=a[i].temp;
		}
		cout<<pans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=a[i].temp;
		dfs(i,1);
	}
	cout<<maxx<<endl;
	return 0;
}
