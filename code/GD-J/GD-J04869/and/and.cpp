#include <bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],b[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	    cin>>a[i];
	    b[a[i]]++;
	    c[i]=a[i];
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
       	    if(b[j]<b[j+1]){
       		    swap(b[j],b[j+1]);
       		    swap(c[j],c[j+1]);
       	    }
	   } 
	}
	for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
       	    if(b[j]==b[j+1]){
       		    if(c[j]<c[j+1]){
				    swap(b[j],b[j+1]);
       		        swap(c[j],c[j+1]);
       		    }
       	    }
	   } 
	}
	cout<<c[1];
    return 0;
}
