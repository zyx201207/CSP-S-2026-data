#include<bits/stdc++.h>
using namespace std;
int a[500005],m,n,z[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
        int b[500005],l=1;
        for(int j=i;j<=n;j++){
	        b[l]=a[j];
	        for(int c=1;c<l;c++){
	            if(b[c]==b[l]){
	            	l=c;
				}
	        }
	        l++;
	    }
	    for(int j=1;j<l;j++){
	        z[b[j]]++;
	    }
    }
    for(int i=1;i<=m;i++){
	    cout<<z[i]<<" ";
	}
	return 0;
}
