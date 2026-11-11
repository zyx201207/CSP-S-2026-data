#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long maxx=0;
long long ma=0,sum,suml,sumr;
int n,m;
bool b=1;
void dfs(int l,int h,long long sum){
	if(l>m){
		maxx=max(maxx,sum);
		return;
	}
	if(h==n) return;
	if(l==1){
		for(int i=1;i<n;i++){
			dfs(2,i,a[i]);
		}
	}
	for(int i=h;i<n;i++){
		dfs(l+1,i,(a[i]&sum));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sum=a[1];suml=a[1];sumr=a[2];
	for(int i=1;i<=n;i++){
		sum=(sum&a[i]);
	}
	for(int i=1;i<n;i++){
		suml=(suml&a[i]);
	}
	for(int i=2;i<=n;i++){
		sumr=(sumr&a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<ma;
		return 0;
	}else if(m==n){
		cout<<sum;
		return 0;
	}else if(m==n-1){
		cout<<max(suml,sumr);
		return 0;
	}else{
		dfs(1,0,0);
	}
	cout<<maxx;
	return 0;
}
