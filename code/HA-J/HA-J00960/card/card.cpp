#include<bits/stdc++.h>
using namespace std;
int a[500005]={ },ans[300005]={ },ord[300005]={ },tong[300005]={ };
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			tong[a[i]]++;
            if(tong[a[i]]=1){
    	    ord[a[i]]=i;
    	    for(int j=1;j<=i;j++){
    	    	if(ord[a[j]]!=0){
    	    		ans[a[j]]++;
    	    	}
    	    }
        }
        else if(tong[a[i]]>1){
    	for(int j=ord[a[i]];j<i;j++){
    		ord[a[j]]=0;
    		tong[a[j]]=0;
    	}
    	ord[a[i]]=i;
    	for(int j=1;j<=i;j++){
    		if (ord[a[j]]!=0){
    			ans[a[j]]++;
    		//	cout<<ans[a[j]]<<;
    		}
    	}
		}
    
    }
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
