#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	string b,e;
	int d=0;
	int c[10000]={0};
	int wc;
	cin>>wc;
	for(int d=0;d<wc;d++){
		cin>>a;
		c[d]=a;
		cin>>b;
		e=e+b;	
	}
	string zp;
	for(int nb=0;nb<wc;nb++){
		for(int zpnb=0;zpnb<c[nb];zpnb++){
			zp=zp+e[nb];
		}
	}
	long long zpl=0,pclnb=0,zps;
	string pcl;
	for(int nb=0;nb<wc;nb++){
		zpl=zpl+c[nb]; 
	}
	for(long long zps=zpl-1;zps>=0;zps--){
		pcl=pcl+zp[zps];
	}
	if(pcl==zp) cout<<pclnb;
	else {for(long long zps=0;zps<=zpl/2;zps++){
		if(pcl[zps]!=zp[zps])
		pclnb++;
	} 
	}
	if(pclnb>=10) pclnb=pclnb-1;
		cout<<pclnb;
}
