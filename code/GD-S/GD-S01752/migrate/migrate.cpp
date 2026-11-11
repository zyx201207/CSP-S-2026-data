#include<bits/stdc++.h>
using namespace std;

int const maxn=1e6;
int x[maxn];
int j[maxn];
int c,t,n,d,A=0,B=0,C=0;
int dfs(int l,int r){
    int f=x[l]-x[r];
    if(f<=d) return 1;
    else if(2*d==f+1) return 2;
    else{
        return dfs(1,l+(r-l)/2)*dfs(l+(r-l)/2,n);
    }
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	int ans=0;
	cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=2;i<=n;i++){
        j[i]=x[i]-x[i-1];
        if(j[i]==j[i-1]) A++;
    }
    if(A==n-2){
        int f=x[n]-x[1];
       	for(int l=1;l<n;l++){
       		for(int r=2;r<=n;r++){
       			if(dfs(l,r)==2) ans++;
		}	
		}
		cout<<ans<<'\n';
    }
    else{
    	cout<<2<<'\n';
	}
	}
	return 0;
}

