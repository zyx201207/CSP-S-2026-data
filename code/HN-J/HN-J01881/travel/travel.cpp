#include <bits/stdc++.h>
using namespace std;
struct op{
	int cx;//³µÏáºÅ
	string zw;//×ùÎ»ºÅ 
}a[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m[4]={0};
	for(int i=0;i<2;i++){
		cin>>a[i].cx>>a[i].zw;
	}
	if(a[0].cx==a[1].cx){
		m[0]=1;
		if(a[0].zw[0]+a[0].zw[1]==a[1].zw[0]+a[1].zw[1]){
			m[1]=1;
			if(a[0].zw[2]>='A'&&a[0].zw[2]<='C'){
				if(a[1].zw[2]>='A'&&a[1].zw[2]<='C'){
					m[2]=1;
					if(a[0].zw[0]==a[1].zw[0]&&a[0].zw[1]==a[1].zw[1]){
						if(abs(a[0].zw[2]-a[1].zw[2])==1){
							m[3]=1;
						}
					}
				}		
			}
			else if(a[0].zw[2]=='f'||a[0].zw[2]=='D'){
				if(a[1].zw[2]=='F'||a[1].zw[2]=='D'){
					m[2]=1;
					if(a[0].zw[0]==a[1].zw[0]&&a[0].zw[1]==a[1].zw[1]){
						if(abs(a[0].zw[2]-a[1].zw[2])==1){
							m[3]=1;
						}
					}
				}		
			}
		}
	}
	
	
	
	
	for(int i=0;i<4;i++){
		cout<<m[i];
	}
	return 0;
} 
