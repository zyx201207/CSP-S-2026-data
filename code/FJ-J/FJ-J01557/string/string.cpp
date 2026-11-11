#include<bits/stdc++.h>
using namespace std;
long long wjy_su=0,wjy_n=0;
struct wjy_str{
	long long wjy_nu;
	char wjy_c;
}wjy_a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>wjy_n;
	for(long long wjy_i=0;wjy_i<wjy_n;wjy_i++){
		cin>>wjy_a[wjy_i].wjy_nu>>wjy_a[wjy_i].wjy_c;
	}
	for(long long wjy_i=0,wjy_j=wjy_n-1;wjy_i<=wjy_j;){
		if(wjy_a[wjy_j].wjy_c!=wjy_a[wjy_i].wjy_c){
			wjy_su+=min(wjy_a[wjy_j].wjy_nu,wjy_a[wjy_i].wjy_nu);
			if(wjy_a[wjy_j].wjy_nu>wjy_a[wjy_i].wjy_nu){
				wjy_a[wjy_j].wjy_nu-=wjy_a[wjy_i].wjy_nu;
				wjy_a[wjy_i].wjy_nu=0;
				wjy_i++;
			}else if(wjy_a[wjy_j].wjy_nu<wjy_a[wjy_i].wjy_nu){
				wjy_a[wjy_i].wjy_nu-=wjy_a[wjy_j].wjy_nu;
				wjy_a[wjy_j].wjy_nu=0;
				wjy_j--;
			}else{
				wjy_a[wjy_i].wjy_nu=0;
				wjy_a[wjy_j].wjy_nu=0;
				wjy_i++;
				wjy_j--;
			}
		}else{
			if(wjy_a[wjy_j].wjy_nu>wjy_a[wjy_i].wjy_nu){
				wjy_a[wjy_j].wjy_nu-=wjy_a[wjy_i].wjy_nu;
				wjy_a[wjy_i].wjy_nu=0;
				wjy_i++;
			}else if(wjy_a[wjy_j].wjy_nu<wjy_a[wjy_i].wjy_nu){
				wjy_a[wjy_i].wjy_nu-=wjy_a[wjy_j].wjy_nu;
				wjy_a[wjy_j].wjy_nu=0;
				wjy_j--;
			}else{
				wjy_a[wjy_i].wjy_nu=0;
				wjy_a[wjy_j].wjy_nu=0;
				wjy_i++;
				wjy_j--;
			}
		}
	}
	cout<<wjy_su;
	return 0;
} 
