#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005],f[500005];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n<5005){
	    for(int i=a[1];i<=a[n];i++){
	    	int V=m,cnt=0;
	    	for(int j=1;j<=n;j++){
	    		f[j]=i-a[j];
	    	}sort(f+1,f+n+1);
	    	for(int k=1;k<=n;k++){
	     		if(f[k]<0) continue;
	    		if(V<f[k]) break;
	    		V-=f[k];
	    		cnt++;
	    	}ans=max(ans,cnt);
    	}
    	cout<<ans;
    }
    else{
    	int stadard=a[n/2];
    	for(int j=1;j<=n;j++){
	    	f[j]=stadard-a[j];
	    }sort(f+1,f+n+1);
	    int V=m;
	    for(int k=1;k<=n;k++){
	     	if(f[k]<0) continue;
	    	if(V<f[k]) break;
	    	V-=f[k];
	    	ans++;
	    }
	    cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

