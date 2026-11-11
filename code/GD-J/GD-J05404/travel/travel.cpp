#include<bits/stdc++.h>
using namespace std;

int zw_r[5],zw_x[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rx,rz,xx,xz;
	cin>>rx>>rz>>xx>>xz;
	
	//
	if(rx==xx){
		cout<<'1';
		int i=1;
		for(char l:rz){
			if(i<=2){
				zw_r[1]*=0;
				zw_r[1]+=(l-'0');
				i++;
			}else{
				zw_r[2]=(l-'A'+1);
			}
		}		
		i=1;
		for(char l:xz){
			if(i<=2){
				zw_x[1]*=0;
				zw_x[1]+=(l-'0');
				i++;
			}else{
				zw_x[2]=(l-'A'+1);
			}
		}
		
		//
		if(zw_r[1]==zw_x[1]){
			cout<<'1';
			bool flag=1;
			int rl[5];
			if(zw_r[2]>=1&&zw_r[2]<=3){
				rl[1]=1;
			}else{
				rl[1]=0;
			}
			if(zw_x[2]>=1&&zw_x[2]<=3){
				rl[2]=1;
			}else{
				rl[2]=0;
			}
			
			//
			if(rl[1]==rl[2]){
				cout<<'1';
				
				//
				if(abs(zw_x[2]-zw_r[2])==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
				//判断：两张车票对应的座位是否相邻 
			}else{
				cout<<"00";
				return 0;
			}//判断：两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧 
			
		}
		else{
			cout<<"000";
			return 0;
		}//判断：两张车票对应的座位是否在同一节车厢的同一排 
		
	}else{
		cout<<"0000";
		return 0;
	}//判断： 两张车票对应的座位是否在同一节车厢
	
	return 0;
} 
