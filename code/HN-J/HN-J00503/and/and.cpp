#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ans=0,a1=0;
	for(int i=0;i<n;i++) {cin>>a[i];
	}
	int w=m;
	int b[m];
	int q=a[0] and a[1];
while(w>=1){for(int j=0;j<m;j++){
	for(int k=0;k<n;k++){
		b[j]=a[k];
		for(int z=k+1;z<n;z++){
		b[z]=a[k];
		if(q<=b[j] and b[z]){q=b[j] and b[z];
		}
	}
}
}
w=w-1;
}
	cout<<q;
	
	
	
	
	return 0;
} 
