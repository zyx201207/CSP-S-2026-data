#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000],ans=-99999;
bool f[500000]={0};

void dfs(long long k,long long t){
	if(k==m){
		ans=max(ans,t); return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(k+1,t & a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
   for(int i=1;i<=n;i++){
   	    f[i]=1;
    	dfs(1,a[i]);
    	f[i]=0;
	}
    
    cout<<ans;
	return 0;
}
