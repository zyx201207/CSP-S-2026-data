#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,mx=-1001000,k=1;
int a[500010],c[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
       cin >> a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(c[i]<c[j]) swap(c[i],c[j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]) swap(a[i],a[j]);
        }
    }
	for(int i=1;i<n;i++){
        c[i] = a[i+1]-a[i];
	}
	for(int h=1;h<=n;h++){
		k=1;
		for(int i=h;i<=n;i++){
    	    if(s<=m){
    		    s += s+c[i]*h;
    	        k++;
    	        if(k>mx){
    	        	mx = k;
				}
		    }
	    }
	}
    cout << mx;
	return 0;
}
