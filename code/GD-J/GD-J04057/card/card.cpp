#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[10000005],c[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j-i+1]=a[j];	
			for(int k=j-i+1;k>=i;k--){
				if(b[j-i+1]==b[k]){
					for(int l=k;l<=j-i+1;l++){
						b[l]=0;
					} 
				}
			}
		}
		sort(b+1,b+n+1,cmp);
		int s=1;
		while(b[s]!=0){
			if(b[s]==i) c[b[s]]++;
			s++;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0) cout<<c[i];
	}
	return 0;
} 
