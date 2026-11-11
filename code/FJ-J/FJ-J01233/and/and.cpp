#include<bits/stdc++.h>
using namespace std;
int n,m,num[4];
long long a[200005],amax=LLONG_MIN,ans,res[25],tot;
bool f;
void check(){
	ans=(a[res[1]]&a[res[2]]);
	for(int i=3;i<=m;i++) ans=(ans&a[res[i]]);
	amax=max(amax,ans);
}
void dfs(int now,int has){
	if(now>n) return;
	res[has]=now;
	if(has==m) check();
	dfs(now+1,has+1);
	dfs(now+1,has);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) amax=max(amax,a[i]);
		cout<<amax;
		return 0;
	}
	if(m==n){
		ans=(a[1]&a[2]);
		for(int i=3;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
				amax=max(amax,(a[i]&a[j]));
		cout<<amax;
		return 0;
	}
	if(n<=20){
		dfs(1,1);
		cout<<amax;
		return 0;
	}
	for(int i=1;i<=n;i++){
		tot+=a[i];
		if(tot>4) tot=-1;
	}
	if(tot!=-1){
		for(int i=1;i<=n;i++) num[a[i]]++;
		if(num[1]+num[2]+num[3]<m){
			cout<<0;
			return 0;
		}
		if(num[2]+num[3]>=m){
			cout<<2;
			return 0;
		}
		if(num[1]+num[3]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) f=1;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
