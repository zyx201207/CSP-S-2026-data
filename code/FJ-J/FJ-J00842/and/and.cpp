#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,a[maxn],
	long long w=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=0,x=0;
    if(m=1){
        w=1;
    }
    for(m=2;m<=n;m++){
    while(l++){
    if(m=2)	{
    	if(l==n) break;
    	while(r++){
    		w=max{a[l]|a[r],w};
    		if(r==n) break;
		}
	}
    if(m=3){
        while(l++){
    	    if(l==n-1) break;
        	while(x++){
        		if(x==n) break;
    	        while(r++){
    	    	    w=max{a[l]|a[x]|a[r],w};
    		        if(r==n) break;
    		    }
		    }
	    }
    }
}
    cout<<w;
    return 0;
}
