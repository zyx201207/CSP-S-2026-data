#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx=-1; 
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    if(m==1){
    	for(int i=1;i<=n;i++) mx=max(mx,a[i]);
    	cout<<mx;
    }
    else if(m==2){
    	int ji;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			ji=a[i]&a[j];
    			mx=max(mx,ji);
    		}
    	}
    	cout<<ji;
    }
    else if(m==3){
    	int ji;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			for(int k=1;k<=n;k++){
    				ji=a[i]&a[j]&a[k];
    				mx=max(mx,ji);
    			}
    		}
    	}
    	cout<<mx;
    }
    else if(m==n){
    	int ji=a[1]&a[2];
    	for(int i=3;i<=n;i++){
    		ji=ji*a[i];
    	}
    	cout<<ji;
    }
    else{
    	for(int i=1;i<=n;i++){
    		int ji;
    		for(int j=1;j<=n;j++){
    			if(j!=i) ji=ji&a[j];
    		}
    		mx=max(mx,ji);
    	}
    	cout<<mx;
    }
	 return 0;
}
