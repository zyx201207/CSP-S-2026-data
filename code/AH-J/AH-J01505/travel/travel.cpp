#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
	
    FILE *fin,*fout;
    fin=fopen("travel.in","r");
    fout=fopen("travel.out","w");
    char a[10],b[10],c[10],d[10];
    char sum[10]={'1','1','1','1'};
    fscanf(fin,"%c%c %c%c%c %c%c %c%c%c",&a[0],&a[1],&b[1],&b[2],&b[3],&c[0],&c[1],&d[0],&d[1],&d[2]);
    if(a[0]==c[0] && a[1]==c[1]){
     sum[0]='1';
    }
    else if(b[0]==d[0]&& b[1]==d[1]){
     sum[1]='1';
     if(b[2]=='F'){
         if(d[2]=='D'){
             sum[2]='1';
             sum[3]='1';
         }
     }
     if(b[2]=='D'){
         if(d[2]=='F'){
             sum[2]='1';
             sum[3]='1';
         }
     }
     else {
         if(b[2]=='C'||b[2]=='B'||b[2]=='A'){
            if(d[2]!='F'&&d[2]!='D'){
                sum[2]='1';
                if(b[2]=='B' || d[2]=='B'){
                    sum[3]='1';
                }
                else if(b[2]=='C'&&d[2]=='B'){
                    sum[3]='1';
                }
                
            }
         }
         }
    }
    fprintf(fout,"%c%c%c%c",sum[0],sum[1],sum[2],sum[3]);
   
    return 0;
    }
