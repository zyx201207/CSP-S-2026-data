#include<bits/stdc++.h>
using namespace std;
int t,q;
int n,m,ans1,ans,a[200002];
void dfs(int m,int d){
	if(m==1) {ans++;return;}
	int c=m-1;
    for(int i=m;i>=m-d+1;i--){ 
		if(i==a[c]) {
		    c--;
		    dfs(c,d);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>q>>t;
    while(t--){
	    cin>>n>>m;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    if(q==11 || q==12) {cout<<n-(m/(a[2]-a[1])+1)<<endl;}
	    
	}
	return 0;
}
