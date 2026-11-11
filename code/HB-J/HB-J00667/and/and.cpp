#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],tnt=0,k=0,b=100000000000000000,p=0,l=0;
void dfs(int x,int g,int h){
	if(g==m){
		tnt=max(tnt,h);
		return;
	}
	if(x>n) return;
	if(g==0) dfs(x+1,g+1,a[x]);
	else dfs(x+1,g+1,h&a[x]);
	dfs(x+1,g,h);
}
int pd(int x){
	if(x==0) return false;
	while(x!=0){
		if(x%2==1&&x!=1) return false;
		x/=2;
	}
	return true;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pd(a[i]+1)==0) k=1;
		if(a[i]>=4) p=1;
		if(a[i]!=i-1) l=1;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n){
		tnt=a[1];
		for(int i=2;i<=n;i++){
			tnt=tnt&a[i];
		}
		cout<<tnt;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				tnt=max(tnt,a[i]&a[j]);
			}
		}
		cout<<tnt;
	}
	else if(p==0){
		int f=0,s=0,t=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3) t++;
			else if(a[i]==2) s++;
			else f++;
		}	
		if(m<=t) cout<<3;
		else if(m<=t+s) cout<<2;
		else if(m<=t+f) cout<<1;
		else cout<<0;
	}
	else if(k==0){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else if(l==0&&pd(n)){
		tnt=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			tnt=tnt&a[i];
		}
		cout<<tnt;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++) b=min(b,a[i]);
		if(b==1) tnt=a[2];
		else tnt=a[1];
		for(int i=1;i<=n;i++){
			if(i!=b) tnt=tnt&a[i];
		}
		cout<<tnt;
	}
	else{
		dfs(1,0,0);
		cout<<tnt;
	}
	return 0;
}
