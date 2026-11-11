#include<bits/stdc++.h>
using namespace std;
signed main(){
	FILE *fp1=fopen("migrate.in","r"),*fp2=fopen("migrate.out","w");
	long long c,t,cha,lon,bu;
	int rem=0,a,island[200005],n,d;
	fscanf(fp1,"%d",&c);
	fscanf(fp1,"%d",&t);
	for(int i=0;i<t;i++){
		fprintf(fp2,"0");
		memset(island,sizeof(island),0);
		fscanf(fp1,"%d",&n);
		fscanf(fp1,"%d",&d);
		for(int j=0;j<n;j++){
			fscanf(fp1,"%d",&a);
			island[j]=a;
		}
		rem=0;
		cha=island[1]-island[0];
		bu=d/cha;
		if(d<2*cha){
			fprintf(fp2,"0");
			break;
		}
		for(int k=0;k<n-2;k++){
			for(int j=k+3;j<n;j++){
				lon=cha*(j-k);
				if(d>=lon) break;
				if((j-k)%bu==0)
					break;
				else if((j-k)/bu==1)
					rem+=1;
			}
		}
		fprintf(fp2,"0");
		fprintf(fp2,"%d",rem);
	}
	return 0;
}
