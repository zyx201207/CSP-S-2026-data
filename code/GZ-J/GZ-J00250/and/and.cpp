//GZ-J00250 贵阳市新世界学校 李宗运
#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1;
long long a[200005],maxb[200005],T=0;
long long dfs(long long p,long long l){
	if(p>m){
		T+=1;
		return a[l];
	}
	for(int i=l;i<=n;i++){
		maxb[T]=(a[i]&dfs(p+1,i+1));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n){
		long long h=a[1];
		for(int i=2;i<=n;i++){
			h=h&a[i];
		}
		cout<<h;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		long long maxa=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxa=max(maxa,(a[i]&a[j]));
		cout<<maxa;
	}
	else {
		dfs(1,1);
		long long maxc=-1;
		for(int i=1;i<=T;i++)maxc=max(maxc,maxb[i]);
		cout<<maxc;
	}
	return 0;
} 
