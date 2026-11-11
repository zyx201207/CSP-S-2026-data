#include<bits/stdc++.h>
using namespace std;
long long wjy_n=0,wjy_ma=0,wjy_m=0,wjy_a[200100],wjy_b=0,wjy_nn[20]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};
bool wjy_bo=false;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>wjy_n>>wjy_m;
	for(long long wjy_i=0;wjy_i<wjy_n;wjy_i++){
		cin>>wjy_a[wjy_i];
	}
	if(wjy_m==wjy_n){
		for(int wjy_i=1;wjy_i<wjy_n;wjy_i++){
			wjy_a[0]=wjy_a[0]&wjy_a[wjy_i];
		}
		cout<<wjy_a[0];
		return 0;
	}
	sort(wjy_a,wjy_a+wjy_n,cmp);
	for(long long wjy_i=0;wjy_i<wjy_n;wjy_i++){
		if(wjy_b+1<wjy_m){
			for(long long wjy_j=0;wjy_j<20;wjy_j++){
				if(wjy_a[wjy_i]==wjy_nn[wjy_j]){
					wjy_ma=max(wjy_ma,wjy_j);
					wjy_a[wjy_i]=0;
					wjy_b++;
				}
			}
		}else{
			wjy_bo=true;
			break;
		}
	}
	if(wjy_bo==true){
		sort(wjy_a,wjy_a+wjy_n,cmp);
		long long wjy_e=0;
		while(wjy_a[wjy_e]>wjy_nn[wjy_ma]){
			wjy_e++;
		}
		cout<<wjy_a[wjy_e];
		return 0;
	}
	return 0;
} 
