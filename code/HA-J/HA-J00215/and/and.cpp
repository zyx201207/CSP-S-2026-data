#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	int a[105];
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
    for(int j=0;j<=m;j++){
    	if(m==2){
    	    maxn=max(a[j],a[j+1]);}
    	else if(m==3){
    		maxn=max(a[j],a[j+1],a[j+2]);
		}
	}
	cout<<maxn;
	
    return 0;
}
