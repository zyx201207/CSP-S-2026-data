#include<bits/stdc++.h>
using namespace std;
int n,m,r[1001],jg[3]={0},o[10001],k[10001]={0},d;
void ww(int i){
	for(int e=1;e<=n;e++){
		if(k[e]==0){
			o[e]=r[e];
			k[e]=1;
			if(i==m){
				if(m==2){
					jg[2]=o[1] and o[2];
				}
				if(m==3){
					jg[2]=o[1] and o[2] and o[3];
				}
				if(m==4){
					jg[2]=o[1] and o[2] and o[3] and o[4];
				}
				if(m==5){
					jg[2]=o[1] and o[2] and o[3] and o[4] and o[5];
				}
				if(m==6){
					jg[2]=o[1] and o[2] and o[3] and o[4] and o[5] and o[6];
				}
				if(m==7){
					jg[2]=o[1] and o[2] and o[3] and o[4] and o[5] and o[6] and o[7];
				}
				if(jg[2]>jg[1]){
					jg[1]=jg[2];
					jg[2]=0;
				}
			}
			else{
				ww(i+1);
				k[e]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	ww(1);
	cout<<jg[1];
	return 0;
}
