#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1=-1,max2[200005];
int main(){
    cin.sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		for(int i=1;i<=n;i++){
			max1=max(max1,a[i]);
		}
		cout<<max1;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int q=a[i]&a[j];
				max1=max(max1,q);
			}
		}
		cout<<max1;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(max1==-1){
				max1=a[i];
			}
			max1=max1&a[i];
		}
		cout<<max1;
	}
	else if(m==n-1){
		for(int j=1;j<=n;j++){
			if(max1==-1){
				max2[j]=a[j];
   			}
    		max2[j]=max2[j]&a[j];
	    }
		for(int i=1;i<=n;i++){
	  		max2[i]=max2[i]|a[i];
	    	
	    }
	    sort(max2+1,max2+n+1);
	    cout<<max2[n];
	}
    return 0;
}
