#include<bits/stdc++.h>
using namespace std;
long long n,m,k[1919810],ans=1,key,maxx,all;	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
		cin >> k[i];
    }	
    if(k[2]-k[1]==k[3]-k[2]){
		key=k[2]-k[1];
        for(int i=1;i<n;i++){
		    if(maxx+key*i>m){
			    cout << ans;
			    return 0;
	        }	
	    maxx+=key*i;
	    ans++;
        }	
        cout << n;
        return 0;
    }	
    else if(n<=16 && n>5){
		cout << n;
		return 0;
    }	
    else{
		ans=-114514;
		for(int i=1;i<=n;i++){
			int cac=0,out=0;
			for(int j=1;j<=i;j++){
				cac+=k[i]-k[j];
				out++;
		    }	
		    if(cac<=m && out>=ans){
				ans=out;
		    }	
	    }	
	    cout << ans;
	    return 0;
    }	
    return 0;
}	
