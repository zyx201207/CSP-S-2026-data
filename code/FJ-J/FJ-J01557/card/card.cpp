#include<bits/stdc++.h>
using namespace std;
long long wjy_n=0,wjy_m=0,wjy_a[500050]={0},wjy_b[300030]={0},wjy_su[300030][2],wjy_su1[300030]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>wjy_n>>wjy_m;
	for(long long wjy_i=0;wjy_i<wjy_n;wjy_i++){
		cin>>wjy_a[wjy_i];
		wjy_b[wjy_a[wjy_i]]++;
	}
	for(long long wjy_i=0;wjy_i<wjy_n;wjy_i++){
		for(long long wjy_j=wjy_i;wjy_j<wjy_n;wjy_j++){
			if(wjy_su[wjy_a[wjy_j]][0]==1){
				for(long long wjy_k=wjy_su[wjy_a[wjy_j]][1];wjy_k<wjy_j;wjy_k++){
					wjy_su[wjy_a[wjy_k]][0]=0;
					wjy_su[wjy_a[wjy_k]][1]=0;
				}
				wjy_su[wjy_a[wjy_j]][0]=1;
				wjy_su[wjy_a[wjy_j]][1]=wjy_j;
			}else{
				wjy_su[wjy_a[wjy_j]][0]=1;
				wjy_su[wjy_a[wjy_j]][1]=wjy_j;
			}
		}
		for(long long wjy_j=1;wjy_j<=wjy_m;wjy_j++){
			if(wjy_su[wjy_j][0]==1){
				wjy_su[wjy_j][0]=0;
				wjy_su1[wjy_j]++;
			}
		}
	}
	for(long long wjy_j=1;wjy_j<=wjy_m;wjy_j++){
		if(wjy_j==wjy_m){
			cout<<wjy_su1[wjy_j];
		}else{
			cout<<wjy_su1[wjy_j]<<" ";
		}
	}
	return 0;
} 
