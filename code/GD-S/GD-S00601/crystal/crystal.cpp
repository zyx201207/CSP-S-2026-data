#include<bits/stdc++.h>
using namespace std;
int cha[50005];
signed main(){
	FILE *fp1=fopen("crystal.in","r"),*fp2=fopen("crystal.out","w");
	long long n,m;
	vector<int>	crystal;
	fscanf(fp1,"%d",&n);
	fscanf(fp1,"%d",&m);
	int num,mid,size,add,max=0;
	for(int i=0;i<n;i++){
		fscanf(fp1,"%d",&num);
		crystal.push_back(num);
	}
	for(int i=0;i<n;i++){
		mid=m;
		size=0;
		for(int j=0;j<n;j++){
			add=crystal[j]-crystal[i];
			if(add<0) add-=add*2;
			cha[j]=add;
		}	
		sort(cha,cha+n);
		for(int k=0;k<n;k++){
			if(mid>=cha[k]){
				size+=1;
				mid-=cha[k];
			}
			else{
				if(size>max) max=size;
				break;
			}
		}
	}
	fprintf(fp2,"%d",max);
	return 0;
}
