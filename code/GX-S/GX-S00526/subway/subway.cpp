#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    FILE *fp1,*fp2;
    long c,n,m,d,q,w[10000],a[1000][1000],t[1000][1000],j,x[10000],y[10000],s,i,k[10000],r,g,h,T;
    fp1=fopen("subway.in","r");
    fp2=fopen("subway.out","w");
    fscanf(fp1,"%d %d %d %d %d",&c,&n,&m,&d,&q);
    for (s=0;s<m;s=s+1){
        fscanf(fp1,"%d",&w[s][2]);
    }
    for (i=1;i<=n;i=i+1){
        fscanf(fp1,"%d",&k[0][i+2]);
        for (j=0;j<=k[i];j=j+1){
                fscanf(fp1,"%d %d",&a[2j+1][i+2+j],&t[2j+2][i+2+j]);
        }
    }
    for (r=0;r<=q;r=r+1) {
        fscanf(fp1,"%d %d",&x[r],&y[r]);
    }
    if (m==2) {
        g=x[r];
        h=y[r];
        T=w[g]+w[h]+t[1][1]+t[1][2];
        fprintf(fp2,"%d",T);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
