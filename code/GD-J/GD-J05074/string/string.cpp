#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('string.in','r',stdin);
	freopen('string.out','w',stdout);
	int n;
	cin>>n;
	string zm[n];
	int sz[n];
	int zjs=0;
	int zda=0;
	int qqqqqq=0;
	for(int i=0;i<n;i++){
		cin>>sz[i];
		cin>>zm[i];
		zjs+=sz[i];
		qqqqqq++;
		
	}
	zjs=zjs/2;
	string zmq[zjs];
	int szq[zjs];
	string zmh[zjs];
	int szh[zjs];
	int i = 0;
	int jl = 0;
	int cnm = 0;
	int jsb = 0;
	int cdp=0;
	int cdh=0;
	while(jsb==1){
		jl+=sz[i];
		if (jl<zjs){
			zmq[i]=zm[i];
			szq[i]=sz[i];
			cdp++;
		}else{
			zmq[i]=zm[i];
			szq[i]=zjs-(jl-sz[i]);
			cdp++;
			if(jl!=zjs){
				zmh[0]=zm[i];
				if(sz[i]%2==0){
					szh[0]=jl-zjs;	
				}else{
					szh[0]=jl-zjs-1;
				}
				cdh++;

			}
			cnm = i;
			jsb = 1;
		}
		i++;
	}
	i = 1;

	while(i+cnm<qqqqqq){
		zmh[i]=zm[i+cnm];
		szh[i]=sz[i+cnm];
		cdh++;
		i++;
	}
	int zdz=0;
	for(int j=0;j<cdp;j++){
		if(zdz<szq[j]){
			zdz=szq[j];
		}
	}
	int zdzh=0;
	for(int k=0;k<cdh;k++){
		if(zdzh<szh[k]){
			zdzh=szh[k];
		}
	}

	int www=0;
	int wwwh = cdh-1;
	int zssy=0;
	int zssyh =0;
	int sy=0;
	int syh=0;
	int cs=0;

	while(www<cdp){
		zssy = 0;
		sy = 0;
		while(zssy<=www){
			zssy+=szq[sy];
			sy++;
		}
		zssyh = 0;
		syh = 0;
		while(zssyh<=wwwh){
			zssyh+=szq[sy];
			syh=syh-1;
		}
		if(zmq[sy]!=zmh[syh]){
			cs++;
		}

		www++;
		wwwh=wwwh-1;
	}

	cout<<cs;
	return 0;
}
