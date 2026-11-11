#include<bits/stdc++.h>
using namespace std;
struct a{
	long long b;
	int c;
}d[200005];
int sum(long long e){
	int cnt=0;
	while(e!=0){
		cnt+=e%2;
		e/=2;
	}
	return cnt;
}
bool cmp(a x,a y){
	return x.c>=y.c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long vmax=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i].b;
	}
	int ans=d[1].b;
	if(m==1){
		for(int i=1;i<=n;i++){
			vmax=max(d[i].b,vmax);
		}
		cout<<vmax;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			ans&=d[i].b;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		d[i].c=sum(d[i].b);
	}
	sort(d+1,d+1+n,cmp);
	ans=d[1].b;
	for(int i=2;i<=m;i++){
		ans&=d[i].b;
	}
	cout<<ans;
	return 0;
}
