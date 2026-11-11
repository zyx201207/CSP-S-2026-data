#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m+1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int q[n-i]={0};
		for(int j=0;j<n-i;j++){
			for(int k=0;k<j;k++){
				if(a[i+j]==q[k]){
					for(int l=k;l<j;l++){
						q[l]=0;
					}
					q[k+1]=a[i+j];
				}else{
					q[k+1]=a[i+j];
				}
			}
		}
		for(int j=0;j<n-i;j++){
			if(q[j]!=0){
				int w=q[j];
				b[w]+=1;
			}
		}
	}
	for(int i=1;i<m+1;i++){
		cout<<b[i];
	}
	return 0;
}
