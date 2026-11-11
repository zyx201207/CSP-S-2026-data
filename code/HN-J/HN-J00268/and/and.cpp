#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn=0,a[N],flag[N];

int awy(){
	int fag=0,sum;
	for(int i=1;i<=n;i++){
		if(fag==1 && flag[i]==1){
			int num=a[i];
			sum=(sum & num);
		}
		if(fag==0 && flag[i]==1){
			sum=a[i];
			fag=1;
		}
	}
	return sum;
}
void dfs(int step,int mark){
	if(step==m){
		maxn=max(maxn,awy());
		return ;
	}
	if(mark>n) return ;
	flag[mark]=1;
	dfs(step+1,mark+1);
	flag[mark]=0;
	dfs(step,mark+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<maxn;
	return 0;
} 
