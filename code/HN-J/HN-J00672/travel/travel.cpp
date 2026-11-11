#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a[4];
    string che1,zw1,che2,zw2;
    cin>>che1>>zw1>>che2>>zw2;
    int cnt=0;
    for(int i=0;i<2;i++){
    	if(che1[i]!=che2[i]){
    		a[0]=0;
		}else{
			cnt++;
		}
	}
	if(cnt==2){
		a[0]=1;
	}
	cnt=0;
	for(int i=0;i<2;i++){
		if(zw1[i]!=zw2[i]){
			a[1]=0;
		}else{
			cnt++;
		}
	}
	if(cnt==2){
		a[1]=1;
	}
	if((zw1[2]=='A'||zw1[2]=='B'||zw1[2]=='C')&&(zw2[2]=='A'||zw2[2]=='B'||zw2[2]=='C')||(zw1[2]=='D'||zw1[2]=='F')&&(zw2[2]=='D'||zw2[2]=='F')){
		a[2]=1;
	}else{
		a[2]=0;
	}
	if((zw1[2]-zw2[2]==1||zw2[2]-zw1[2]==1)){
		if(zw1[2]=='C'&&zw2[2]=='D'){
			a[3]=0;
		}else{
			a[3]=1;
		}
	}
	if(a[0]==0){
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}else if(a[1]==0){
		a[2]=0;
		a[3]=0;
	}else if(a[2]==0){
		a[3]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0; 
}
