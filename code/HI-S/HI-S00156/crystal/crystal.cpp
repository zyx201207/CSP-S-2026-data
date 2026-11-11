#include<bits/stdc++.h>
using namespace std;
long long maxn=0;
long long n,m,a[500002],b[500002],c[500002];
void findsame(){
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)c[i]=b[i];
	long long h=1;
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			h++;
		}
		else{
			if(h>=maxn){
				maxn=h;
			}
		}
	}
}
void dfs(long long m1){
	if(m1<=0){
		findsame();
		return;
	}
	for(int j=2;j<=n;j++){
		b[j]++;
		dfs(m1-1);
		b[j]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)b[i]=a[i];
	dfs(m);
	cout<<maxn;
	return 0;
} 
