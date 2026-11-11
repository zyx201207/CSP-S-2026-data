#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	bool ban=0,gd1=0,gd2=0;
	string a,b;
	string c,d;
	int aa[5]={0};
  	cin>>a>>c>>b>>d;
  	int z1=(c[0]-'0')*10+c[1]-'0';
  	int z2=(d[0]-'0')*10+d[1]-'0';
  	if(a==b){
  		aa[0]+=1;
  	}else{
  	    ban=1;
    }
    if(ban==0 && z1==z2){
    	aa[1]+=1;
    }else{
    	ban=1;
    }
    if(c[2]=='D' || c[2]=='F'){
    	gd1=1;
    }
    if(d[2]=='D' || d[2]=='F'){
    	gd2=1;
    }
    if(gd1==gd2 && ban==0){
    	aa[2]+=1;
    }else{
    	ban=1;
    }
    if(ban==0){
	
    if(char(d[2]+1)==c[2] || char(d[2]-1)==char(c[2])){
    	aa[3]+=1;
    }else{
    	ban=1;
    }
    }
    string bb;
    for(int i=0;i<4;i++){
    	bb+=char(aa[i]+'0');
	}
	cout<<bb;
	return 0;
}
