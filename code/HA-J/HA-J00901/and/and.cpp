#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    long long ans=a[1],cnt=1;
    b[1]=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
        b[i]=a[i];
    }
    cnt=m;
    for(int i=m;i<=n;i++){
    	long long wei=0;
    	     for(int j=1;j<=m;j++){
    	     	int ans1;
    	     	if(j==1){
    	     		ans1=b[2];
    	     	}else ans1=b[1];
    	       for(int k=1;k<=m;k++){
    	       	   if(k==j)continue;
    	       	   ans1=ans1&b[k];
    	       }
    	       int r=ans1&a[i];
    	       if(r>ans){
    	       	  ans=r;
    	       	  wei=j;
    	       }
    	     }
    	     if(wei!=0){
    	     	b[wei]=a[i];
    	     }
    }
    cout<<ans;
	return 0;
}

