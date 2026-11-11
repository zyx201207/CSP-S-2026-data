#include<bits/stdc++.h>
using namespace std;
int n,m,a3=-1e9;
int a[200005][1005];
int b[200005]={0},c;
bool d[200005]={0};
int dfs(int maxx,int x,int l){
	if(l==x)
		return maxx;
	else{
		for(int i=1;i<=n;i++){
			if(d[i]==)
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		int a1=c[i],a2;
		b[i]=1;
	    while(a1>0){
	    	a[i][b[i]]=a1%2;
	    	a1/2;
	    	b[i]++;
		}	
	}
	for(int i=1;i<=m;i++)
	a3=max(a3,dfs(-1e9,i,0));
	cout<<a3;
	return 0;
}
