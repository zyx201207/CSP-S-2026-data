#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9;
int n,m,a[N],maxx,sums,b[N],sum;
struct stu{
	int x;
	int c[20];
}d[N];
bool cmp(stu x,stu y){
	for(int i=1;i<=sums;i++){
		if(x.c[i]>y.c[i]) return true;
		else if(x.c[i]==y.c[i]) continue;
		else return false;
	}
	return false;
}
void dfs(int x,int y){
	if(y>=m){
		int f=0,sum=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				if(f==0) f=1,sum=a[i];
				else sum&=a[i];
			}
		}
		maxx=max(maxx,sum);
		return;
	}
	if(x>n) return;
	b[x]=1;
	dfs(x+1,y+1);
	b[x]=0;
	dfs(x+1,y);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
		return 0;
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}
	if(n<=2000&&m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	if(n<=20){
		maxx=0;
		dfs(1,0);
		cout<<maxx;
		return 0;
	}
	while(maxx){
		sums++;
		maxx/=2;
	}
	for(int i=1;i<=n;i++){
		int x=a[i],cnt=0;
		d[i].x=i;
		while(x){
			d[i].c[++cnt]=x%2;
			x/=2;
		}
		cnt++;
		for(int j=cnt;j<=sums;j++) d[i].c[j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sums/2;j++){
			swap(d[i].c[j],d[i].c[n-j+1]);
		}
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sums;j++){
			cout<<d[i].c[j]<<' ';
		}
		cout<<'\n';
	}
	sum=a[d[1].x];
	for(int i=2;i<=m;i++) sum&=a[d[i].x];
	cout<<sum;
	return 0;
}
