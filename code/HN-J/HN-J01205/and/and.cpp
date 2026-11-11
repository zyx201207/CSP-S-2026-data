#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],mmax;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];	
	}
    if(m==1){
    	for(int i=1;i<=n;i++){
    		mmax=max(mmax,a[i]);
		}
	}else{
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			int b=a[i] and a[j];
				mmax=max(mmax,b);
			}
		}
	}
	cout<<mmax;           
    return 0;
}

