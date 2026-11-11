#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int a[500005];
void qll(int h,int f){
	int u=f-h;
	for(int i=1;i<=u;i++){
		a[h]=a[f];
		h++;
		f++;
	}
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int k=1;
	for(int i=n;i>=1;i--){
		int j=i;
		int v=j;
		for(int l=1;l<=n;l++){
			if(a[k]==a[l]){
				qll(k,l);
				j--;
			}
		}
		if(j==0){
			for(int w=1;w<=n;w++){
				if(v==a[w]){
					sum++;
				}
			}
			cout<<sum;
		}
	}
	return 0;
} 
