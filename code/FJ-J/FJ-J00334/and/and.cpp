#include<bits/stdc++.h>
using namespace std;
long long maxn=-9999999;
int n,m;
int a[200005];
bool cmp(int &t1,int &t2){
	return t1>t2; 
}
int cnt[2000005];
void dfs(int n_wz,int p,int n_and){
	if(n_wz==m){
		if(maxn<n_and){
			maxn=n_and;
		}
		return ;
	}
	for(int i=p;i<=n;i++){
		if(cnt[a[i]]>0){
			if((n_and & a[i])<maxn){
				continue;
			}
			cnt[a[i]]--;
			if(n_wz==0){
				n_and=a[i];
			}
			dfs(n_wz+1,i,(n_and & a[i]));
			cnt[a[i]]++;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	dfs(0,1,0);
	cout<<maxn;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7


*/
