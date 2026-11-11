#include<bits/stdc++.h>
using namespace std;
int n;
int duan[2*10^5], lon[4], biao[2];
char c[27];
string strlon1[3*10^6], strlon2[3*10^6];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>duan[i]>>c[i];
		lon[1]=duan[i]+lon[1];
	}
	if(lon[1]%2==1){
			lon[2]=lon[1]+1;
		}else{
			lon[2]=lon[1];
		}
	for(int i=1;i<=lon[1];i++){
		
		if(i*2<=lon[2]){
			strlon1[i]=c[i];
		}else{
			strlon2[i]=c[i];
		}

	}
	for(int i=1;i<lon[2]/2;i++){
		if(strlon1[i]!=strlon2[lon[2]/2-i]){
			biao[0]++;
		}
	}
	cout<<biao[0];
	
    return 0;
}
