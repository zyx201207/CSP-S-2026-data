#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m[200000]={},n,a,b,d,e[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
	string c[200000]={};
	cin>>a>>b;
    for(int j=0;j<a;j++){
    	cin>>d;
    	for(int i=0;i<30;i++){
    		if(d%e[i]==d){
    			n=i;
    			m[i]=n
    			break;
			}
		}
    	for(int i=n-1;i=>0;i--){
    		if(d%e[i]!=d){
    			c[j]=c[j]+'1';
			}else{
				c[j]=c[j]+'0';
			}
			d=d%e[i];
		}
	}
	for(int j=0;j<a;j++){
		if()
	}
	return 0;
}
