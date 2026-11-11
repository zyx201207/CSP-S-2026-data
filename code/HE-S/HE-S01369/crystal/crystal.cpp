#include<bits/stdc++.h>
using namespace std;
long long ans=1,m,z,n,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
	}
    long long cnt=0;
    for(int j=1;j<=n-1;j++){
    	cnt=1;
	    z=m;
        for(int i=1;i<=n-1;i++){
	        if(z<i*b[i]){
		        break;
		    }
		    else{
		        cnt++;
		        z-=i*b[i];
    	    }
	    }
    	ans=max(cnt,ans);	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
