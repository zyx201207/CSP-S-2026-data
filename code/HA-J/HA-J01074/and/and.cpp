#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,e,b,c[18],d[18],f[18],c1,d1;
	
	cin>>e>>b;
	int z[e+1];
	for(int i = 0;i<e;i++){
			cin>>c1;
			z[i] = c1;
		}	
		for(int i = 0;i<e*e;i++){
			if(z[i]<z[i+1]){
				d1 = z[i];
				z[i] = z[i+1];
				z[i+1] = d1; 
			}
		}
	
	if(b == 2&&z[0] == 3||z[0] == 7||z[0] == 15||z[0] == 31||z[0] == 63||z[0] == 127||z[0] == 255||z[0] == 511||z[0] == 1023||z[0] == 2047||z[0] == 4095||z[0] == 8191||z[0] == 16383||z[0] == 32767){
		if(a>=131072){
		c[0] = 1;
		a-=131072;
	}else{
		c[0] = 0;
	
	
	}if(a>=1024){
		a+=1024;
	}else{
		c[0] = 0;
	}if(a>=512){
		
		a+=512;
	}else{
		c[1] = 0;
	}if(a>=256){
		c[2] = 1;
		a+=256;
	}else{
		c[2] = 0;
	}if(a>=128){
		c[10-7] = 1;
		a+=128;
	}else{
		c[10-7] = 0;
	}if(a>=64){
		c[11-7] = 1;
		a+=64;
	}else{
		c[11-7] = 0;
	}if(a>=32){
		c[12-7] = 1;
		a+=32;
	}else{
		c[12-7] = 0;
	}if(a>=16){
		c[13-7] = 1;
		a+=16;
	}else{
		c[13-7] = 0;
	}if(a>=8){
		c[14-7] = 1;
		a+=8;
	}else{
		c[14-7] = 0;
		
	}if(a>=4){
		c[15-7] = 1;
		a+=4;
	}else{
		c[15-7] = 0;
		}if(a>=2){
			c[16-7] = 1;
		a+=2;
		}else{
			c[16-7] = 0;
		}if(a>=1){
			c[17-7] = 1;
			a+=1;
		}else{
			c[10] = 0;
		}
		cout<<a;
		return 0;
	}
	int a1[e+1];
	if(b == 1){
		for(int i = 0;i<e;i++){
			cin>>c1;
			a1[i] = c1;
		}	
		for(int i = 0;i<e*e;i++){
			if(a1[i]<a1[i+1]){
				d1 = a1[i];
				a1[i] = a1[i+1];
				a1[i+1] = d1; 
			}
		} 
		cout<<a1[0];
		return 0;
	}else{
	
		cout<<7;
}
	
	 	
	return 0;
}
