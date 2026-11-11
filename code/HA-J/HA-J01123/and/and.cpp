#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct node{
	int num,cnt;
}a[10000000];
bool cmp(node x,node y){
	if(x.cnt<0&&y.cnt<0)return x.num>y.num;
	else if(x.cnt<0||y.cnt<0)return x.num<y.num;
	return x.cnt<y.cnt; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].cnt=ceil(log(a[i].num))-a[i].num-1;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].num;
	for(int i=2;i<=m;i++){
		ans=(ans&a[i].num);
	}
	cout<<ans;
	return 0;
}
