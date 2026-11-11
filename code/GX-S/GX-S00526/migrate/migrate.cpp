#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
    FILE *fp1,*fp2;
    long c,t,n,d,a[10000],s,g,h;
    fp1=fopen("migrate.in","r");
    fp2=fopen("migrate.out","w");
    fscanf(fp1,"%ld %ld",&c,&t);
    for (s=0;s<t;s=s+1) {
                fscanf(fp1,"%d %d",&n,&d);
                for (s=0;s<=n;s=s+1) {
                    fscanf(fp1,"%d",&a[s]);
                }
                g=(n*(n-1))/2;

    }
    for (s=0;s<t;s=s+1){
        fprintf(fp2,"%d\n",g);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
