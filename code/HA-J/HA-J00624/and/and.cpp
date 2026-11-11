#include <bits/stdc++.h>
using namespace std;
int a[200010],f[200010];int n,m,w,k=INT_MIN,c=0,l=-1,q=0,q1,q2;
void dfs(int l,int r,int d){
	if(r==m){
		c=max(d,c);
		return;
	}
	if(l>n) return;
	dfs(l+1,r+1,d&a[l]);
	dfs(l+1,r,d);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];w=a[1];
	for(int p=2;p<=n;p++){
		cin>>a[p];
		w=w&a[p];l=max(l,a[p]);
		k=max(k,a[p]);
		if(a[p]==3) q++;
		if(a[p]==1) q1++;
		if(a[p]==2) q2++;
	}
	if(m==n){
		cout<<w;return 0;
	}
	if(m==1){
		cout<<k;return 0;
	}
	if(n>=32){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==2){
		int e=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				e=max(e,a[i]&a[j]);
			}
		}
		cout<<e<<' ';
	}
	if(l<=4){
		if(q>=m){
			cout<<3;
			return 0;
		}
		if(q2+q>=m){
			cout<<2;
			return 0;
		}
		if(q1+q>=m){
			cout<<1;
			return 0;
		}
		else cout<<0;
		return 0;
	}
	int d=pow(2,31)-1;
	dfs(0,0,d);
	cout<<c;
	return 0;
}
