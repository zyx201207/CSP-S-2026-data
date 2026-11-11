#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=200000+100;
int a[N],b[N];
int mmax=-99;
void dfs(int d,int x){
	
	if(d>m){
		int cnt=b[1];
		for(int i=2;i<d;i++){
			cnt=cnt & b[i];
		}
		mmax=max(cnt,mmax);
		return ;
	}
	
	for(int i=x+1;i<=n;i++){
		b[d]=a[i];
		dfs(d+1,i);
		b[d]=0;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(1,0);
	
	cout<<mmax;
	
	return 0;
}
