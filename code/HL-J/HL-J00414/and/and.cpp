#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxa=0,c;
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j+m-1<=n;j++){
		    		for(int l=0;l<m;l++){
		       		    c=a[i]&a[j+l-1];
			        }
			    maxa=max(c,maxa);
	    	}
    	}
	cout<<maxa;
	return 0;
}
