#include<bits/stdc++.h>
using namespace std;
int u=0;
int digui(int n,int b,int erwei[n][30],int erweier[b][30]){
    if(n==0) return 0;
    for(int i=0;i<30;i++){
		if(((erwei[n][i]+digui(n-1,b,erwei[n-1][30],erweier[b][30]))!=0)&&((erwei[n][i]+digui(n-1,b,erwei[n-1][30],erweier[b][30]))%2==0)){
			erweier[u][i]==1;
			u++;
		}
		else erweier[u][i]==0;
	}
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,cd,a,b=0,sd=1;
    int jc[30];
    for(int i=0;i<30;i++){
		js[i]=sd;
		sd*=2;
	}
    cin>>n>>m;
    for(int i=n-m+1;i>=0;i++){
		b+=i;
	}
    int a[n+5],erwei[n][30]=={0},erweier[b][30]=={0};
    for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	int sz[b];
	for(int i=0;i<n;i++){
	    cd=0;
	    for(int j=a[i];j!=0;j=j/2){
		    cd+=1;
		}
		int g[cd];
		cd=0;
		for(int j=a[i];j!=0;j=j/2){
            g[cd]=j=j%2;
		}
		for(int j=0;j<cd;j++){
			erwei[n][j]=g[cd-1-j]
		}
	}
	digui(n,b,erwei[n][30],erweier[b][30])
	for(int i=0;i<b;i++){
		int ss=0;
		for(int j=0;j<30;j++){
			ss+=(erweier[i][j]*sd)
		}
		sz[i]=ss;
	}
	cout<<max(sz);
    return 0;
}
