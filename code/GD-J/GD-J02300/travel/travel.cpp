#include<bits/stdc++.h>
using namespace std;

struct s{
	string x;
	string y;
};
bool cnt[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s zw[10];
	for(int i=1;i<=2;i++){
		cin>>zw[i].x>>zw[i].y;
	}
	if(zw[1].x==zw[2].x){
		cnt[0]++;
		for(int i=0;i<2;i++){
			if(zw[1].y[i]==zw[2].y[i]){
				cnt[i]=1;
			}
			else cnt[1]=0;
		}
		if(cnt[1]==0){
			cnt[2]=0;
			cnt[3]=0;
		}else{
			if(zw[1].y[2]<='C'&& zw[2].y[2]<='C'){
				cnt[2]=1;
				if(zw[1].y[2]==zw[2].y[2]+1 || zw[1].y[2]==zw[2].y[2]-1){
					cnt[3]=1;
				}
			}
			else if(zw[1].y[2]>='D'&& zw[2].y[2]>='D'){
				cnt[2]=1;
				cnt[3]=1;
			}
		}
	}
	else cout<<cnt[0]<<cnt[1]<<cnt[2]<<cnt[3];
	cout<<cnt[0]<<cnt[1]<<cnt[2]<<cnt[3];
	
	return 0;
}
