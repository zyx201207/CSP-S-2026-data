#include <cstdio>
#include <iostream>
using namespace std;
FILE* fout;FILE* fin;
void scan(char* a,auto b){
	fscanf(fin,a,b);
}
int main(){
	fin=fopen("travel.in","r");
	fout=fopen("travel.ans","w");
	//auto fout=f("travel.ans","w");
	int c1,c2,w1,w2;char s1,s2;int a1=false,a2=a1,a3=a1,a4=a1;
	//fin>>c1>>w1>>s1>>c2>>w2>>s2;
	scan("%d",&c1);
	scan("%2d",&w1);
	scan("%c",&s1);
	scan("%d",&c2);
	scan("%2d",&w2);
	scan("%c",&s2);
	//1
	if(c1==c2){
		a1=true;
	}
	//2
	if(a1 && w1==w2){
		a2=true;
	}
	//3
	if(a2){
		if(s1=='D' || s1=='E'){
			if(s2=='D' || s2=='E'){
				a3=true;
			}
		}else{
			if(s2=='D' || s2=='E'){
			}else{
				a3=true;
			}
		}
	}
	if(a3 && (((s1==(s2-1))||(s1==(s2+1))))){
		a4=true;
	}
	fprintf(fout,"%d%d%d%d",a1,a2,a3,a4);
	return 0;
}
