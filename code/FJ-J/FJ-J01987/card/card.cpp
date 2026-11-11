#include<bits/stdc++.h>
using namespace std;
int m,n,a[10000000],b[10000][10000],h[100000];
int main(){

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[100000];
		for(int j=i;j<=n;j++){
			b[i][a[j]]++;
			t[j]=a[j];
			if(b[i][a[j]]>1){
				b[i][a[j]]--;
				for(int l=j-1;t[l]!=a[j];l--){
					if(b[i][a[l]]>=1) b[i][a[l]]--;
				}
			}
	    }
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			h[j]+=b[i][j];
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
