#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
    FILE *fp1,*fp2;
    long n,m,x,y,z,a[1000],s,w,d,e;
    fp1=fopen("crystal.in","r");
    fp2=fopen("crystal.out","w");
    fscanf(fp1,"%ld %ld",&n,&m);
    for (x=1;x<=n;x=x+1){

        fscanf(fp1,"%ld",&a[x]);
    }

      if (n<=5) {
        w=0;
        for (s=0;s<n;s=s+1) {
            for (x=1;x<=n;x=x+1) {
                if (a[x]>a[x+1]) {
                    d=a[x];
                    a[x]=a[x+1];
                    a[x+1]=d;
                }
                w=w+a[x+1];
            }
        for (x=2;x<=n;x=x+1){
            e=e+(a[x]-a[x-1]);
        }

        }
        if ((w+m)%n==0) fprintf(fp2,"%d",n);
        else {
                if ((m-e)%n==0) fprintf(fp2,"%d",n);
        else {
            if (n==2) {
            fprintf(fp2,"%d",1);
            }
            if (n==3) {
                if ((a[1]+m)<a[3]&&(a[2]+m)<a[3]&&m>=(a[2]-a[1])&&m<(2*a[3]-a[1]-a[2])) fprintf(fp2,"%d",2);
                else fprintf(fp2,"%d",1);
            }
            if (n==4) {
                if (m>=(2*a[3]-a[1]-a[2])&&m<(3*a[4]-a[1]-a[2]-a[3])) fprintf(fp2,"%d",3);
                else {
                    if (m<(2*a[3]-a[1]-a[2])&&m>=(a[2]-a[1])) fprintf(fp2,"%d",2);
                    else fprintf(fp2,"%d",1);
                }
            }
            if (n==5) {
                if (m>=(3*a[4]-a[1]-a[2]-a[3])&&m<(4*a[5]-a[1]-a[2]-a[3]-a[4])) fprintf(fp2,"%d",4);
                else {
                    if (m>=(2*a[3]-a[1]-a[2])&&m<(3*a[4]-a[1]-a[2]-a[3])) fprintf(fp2,"%d",3);
                    else {
                        if (m>=(a[2]-a[1])&&m<(2*a[3]-a[1]-a[2])) fprintf(fp2,"%d",2);
                        else fprintf(fp2,"%d",1);
                    }
                }
            }
        }
      }
      }
        else {
            if (n%2==0) fprintf(fp2,"%d",n);
            else fprintf(fp2,"%d",n-1);
        }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
