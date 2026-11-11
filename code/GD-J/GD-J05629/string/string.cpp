#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
char c1[10],c2[10],s1[10],s2[10],w[10]={'A','B','C'},o[10]={'0','1'};
unsigned long long h[10],b=131;
int main(){
	fin=freopen("travel3.in","r",stdin);
	fout=freopen("travel.ans","w",stdout);
	fscanf(fin,"%c",&c1[0]);
	fscanf(fin,"%c",&c1[1]);
	h[0]=c1[0];
	h[1]=h[0]*b+c1[1];
	fscanf(fin,"%c",&s1[0]);
	fscanf(fin,"%c",&s1[0]);
	fscanf(fin,"%c",&s1[1]);
	fscanf(fin,"%c",&s1[2]);
	h[2]=s1[0];
	h[3]=h[2]*b+s1[1];
	fscanf(fin,"%c",&c2[0]);
	fscanf(fin,"%c",&c2[0]);
	fscanf(fin,"%c",&c2[1]);
	h[4]=c2[0];
	h[5]=h[4]*b+c2[1];
	fscanf(fin,"%c",&s2[0]);
	fscanf(fin,"%c",&s2[0]);
	fscanf(fin,"%c",&s2[1]);
	fscanf(fin,"%c",&s2[2]);
	h[6]=s2[0];
	h[7]=h[6]*b+s2[1];
	if(h[1]==h[5]){
		fprintf(fout,"%c",o[1]);
		if(h[3]==h[7]){
			fprintf(fout,"%c",o[1]);
			if(s1[2]>=w[0] && s1[2]<=w[2] && s2[2]>=w[0] && s2[2]<=w[2]){
				fprintf(fout,"%c",o[1]);
				if(s1[2]==w[1] || s2[2]==w[1]){
					fprintf(fout,"%c",o[0]);
				}
				else{
					fprintf(fout,"%c",o[1]);
				}
			}
			else if(s1[2]>w[2] && s2[2]>w[2]){
				fprintf(fout,"%c",o[1]);
				fprintf(fout,"%c",o[1]);
			}
			else{
				fprintf(fout,"%c",o[0]);
				fprintf(fout,"%c",o[0]);
			}
		}
		else{
			fprintf(fout,"%c",o[0]);
			fprintf(fout,"%c",o[0]);
			fprintf(fout,"%c",o[0]);
		}
	}
	else{
		fprintf(fout,"%c",o[0]);
		fprintf(fout,"%c",o[0]);
		fprintf(fout,"%c",o[0]);
		fprintf(fout,"%c",o[0]);
	}
	return 0;
}
