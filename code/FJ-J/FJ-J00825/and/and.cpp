#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int n,a[200010];
int b[200010][30];
int m,l;
int maxx=-INF;
int s[200010][30];
void f(int x,int k){
	l=0;
	while(x){
		b[k][++l]=x%2;
		x/=2;
	}
}
int st[200010];
void dfs(int k,int s,int c){
	if(k>n||c==m){
		if(c<m) return;
		maxx=max(maxx,s);
		return;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			st[i]=1;
			dfs(k+1,a[i],c+1);
			st[i]=0;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(st[i]==0){
				st[i]=1;
				dfs(k+1,a[i]&s,c+1);
				st[i]=0;
			}
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=10||m==2){
		dfs(1,0,0);
		cout<<maxx;
		return 0; 
	}
	if(m==1){
		int k=a[1];
		for(int i=2;i<=n;i++) k=k&a[i];
		cout<<k;
		return 0;
	}
	for(int i=1;i<=n;i++) f(a[i],i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=l;j++) cout<<b[i][j];
//		cout<<endl;
//	}
	for(int i=1;i<=l;i++){
		for(int j=n;j>=1;j--){
			s[j][i]=s[j+1][i]+b[j][i];
//			cout<<s[j][i];
		}
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=l;j++) cout<<s[i][j];
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		int f=0,x=1,ll=l;
		for(int j=l;j>=1;j--){
			if(b[i][j]==1) break;
			ll=j;
		}
		for(int j=1;j<=ll;j++){
			if(j!=1) x*=2;
			if(b[i][j]==0) continue;
			if(s[i][j]>=m) f+=x;
//			cout<<f<<" ";
		}
//		cout<<endl;
		maxx=max(maxx,f);
	}
	cout<<maxx;
	return 0;
}

//4 3
//9611 13443 24625 17755 

