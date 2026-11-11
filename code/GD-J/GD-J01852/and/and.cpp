#include<bits/stdc++.h>
using namespace std;
int m,p;
int s[500005];
int sum=0;
void dfs1(int t,int q,int z){
	if(q>p) return ;
	if(t>m){
		if(q==p) sum=max(sum,z);
		return ;
	}
	dfs1(t+1,q+1,z&s[t]);
	dfs1(t+1,q,z);
}
bool z[200005];
void dfs2(int t,int y){
	if(t>p) {
		sum=max(sum,y);
		return ;
	}
	for(int i=1;i<=m;i++){
		if(!z[i]) {
			z[i]=1;
			dfs2(t+1,y&s[i]);
			z[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>p;
	for(int i=1;i<=m;i++) cin>>s[i];
	if(m<=20){
		dfs1(1,0,2147483647);
		cout<<sum;
	} else if(m==p){
		int r=s[1];
		for(int i=2;i<=m;i++) r=(r&s[i]);
		cout<<r;
	} else if(p<=2){
		dfs2(1,2147483647);
		cout<<sum;
	} else return 0;
}
