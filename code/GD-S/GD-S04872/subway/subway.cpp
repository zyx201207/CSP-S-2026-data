#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	
	long long wy,xl,zhan,duo,jihua,xlzhan,time=0,flag=0,gongyou;
	cin>>wy>>xl>>zhan>>duo>>jihua;
	
	long long zdt[zhan+1];//地铁口到站厅的时间 
	for (int i=1;i<=zhan;i++){
		cin>>zdt[i];
	}
	
	long long xianlu[xl][500001];
	long long zc_time[xl][500001];
	
	cin>>xlzhan;//线路的经过点和转乘时间 
	xlzhan=xlzhan*2;
	for (int i=1;i<=xl;i++){
	
		for (int j=1;j<=xlzhan;j++){
			if (j%2==1){
				cin>>xianlu[i][j];
			}
			else{
				cin>>zc_time[i][j];
			}
		}
	}
	xlzhan=xlzhan/2;
	
	//找两条线路共有的站点
	for (int i=1;i<=xlzhan;i++){
		for (int j=1;j<=xlzhan;j++){
			
			if (xianlu[1][i]=xianlu[2][j])gongyou=xianlu[1][i];
		}
	}
	
	long long start,jieshu;//计划 
	while (jihua--){
		cin>>start,jieshu;
		for (int i=1;i<=xl;i++){
		
			for (int j=1;j<=xlzhan;j++){
				if (xianlu[i][j]==start){
					time=time+zdt[start];
					time=time+zc_time[i][j];
					for (int k=1;k<=xlzhan;k++){//看本线路上有没有终点 
						if (xianlu[i][k]==jieshu){
							time=time+zdt[jieshu];
							time=time+zc_time[i][k];
							cout<<time<<endl;
							time=0;
							flag=1;
							break;
						}
					}
					
					if (flag=1) break;
					
					//本线路无终点换乘 
					for (int k=1;k<=xlzhan;k++){
						if (xianlu[i][k]==gongyou){
							time=time+zc_time[i][k];
							break;
						}
					}
					for (int k=1;k<=xlzhan;k++){
						if (xianlu[i+1][k]==gongyou){
							time=time+zc_time[i+1][k];
							break;
						}
					}
					
					
					for (int k=1;k<=xlzhan;k++){
						if (xianlu[i+1][k]==jieshu){
							time=time+zc_time[i+1][k];
						}
					}
					time=time+zdt[jieshu];
				//	time=time+zc_time[][jieshu];
				}
				if (flag=1) break;
				
				
				
			}
			if (flag=1) break;
		}
		if (flag=0){
		
		cout<<time<<endl;
		time=0;
		}
		else{
			flag=0;
		}
	}
	freopen("subway.out","w",stdout);
	return 0; 
} 
