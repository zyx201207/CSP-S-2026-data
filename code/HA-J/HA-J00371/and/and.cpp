#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,m,p=2147483647,maxx=INT_MIN,flag=1;
int a[N],f[N];
int cm(int n){
	int t=0,k=1;
	while(k!=n){
		k*=2;
		t++;
	}
	return t;
}
void dfs(int k,int s){
	if(s==m){
		for(int i=1;i<=n;++i){
			if(f[i]==1) p=(p&a[i]);
		}
		maxx=max(maxx,p);
		p=2147483647;
		return;
	}
	if(k>n) return;
	dfs(k+1,s);
	f[k]=1;
	dfs(k+1,s+1);
	f[k]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
//		a[i]=i-1;
		if(a[i]!=i-1) flag=0;
	}
	if(n<=20){
		dfs(1,0);
		cout<<maxx<<endl;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;++i){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;++i){
			p=(p&a[i]);
		}
		cout<<p<<endl;
		return 0;
	}
	if(m==n-1){
		return 0;
	}
	if(flag){
		for(int i=n;i>=n-m+1;i--){
			p=(p&a[i]);
		}
		cout<<p<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1]<<endl;
	return 0;
}

