#include<bits/stdc++.h>
using namespace std;

long long aa[1000000000]={},bb[1000000000][1000000000]={},cc[1000000000][2]={},dd[1000000000]={},mk[10000000000]={},a,b,c,d,e,f[1000000000]={};
mm(int n,int m,int z,int ss){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	if(cc[z][0]==n){
		mk[z]=m;
		if(mk[z]<m){
			mk[z]=m;
		}
		return 0;
	}
	if(a<22){
		if(ss==20){
			return 0;
		}
	}else{
		if(a>23){
			if(ss==20){
				return 0;
			}
		}else{
			if(ss==2){
				return 0;
			}
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<f[i];j++){
			if(bb[i][j*2]==n){
				for(int j=0;j<f[i];j++){
					return mm(bb[i][j*2],m+bb[i][j*2+1],z,ss+1);
				}
				break;
			}
		}
	}
	return 0;
    }
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++){
		cin>>aa[i];
	}
	for(int i=0;i<b;i++){
		cin>>f[i];
		for(int j=0;j<f[i]*2;j++){
			cin>>bb[i][j];
		}
	}
	for(int i=0;i<e;i++){
		cin>>cc[i][0]>>cc[i][1];
	}
	for(int i=0;i<e;i++){
		mm(cc[i][1],aa[cc[i][0]]+aa[cc[i][1]],i,1);
		cout<<mk[i];
	}

	return 0;
} 
