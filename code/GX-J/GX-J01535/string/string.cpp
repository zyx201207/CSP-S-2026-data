#include<bits/stdc++.h>
using namespace std;
int main(){
   //freopen("string.in","r",stdin);
   //freopen("string.out","w",stdout);
    char a[1000000] ;
    int n;
    scanf("%d",&n);
    int b[100005],x=1,e=0;

    char c[100005],v;

    for(int i=1;i<=n;i++){
        scanf("%d %c",&b[i],&c[i]);
        if(b[i]>e){
            e=b[i];
            v=c[i];
        }

        for(int j=1;j<=b[i];j++){
            a[x]=c[i];
            x++;
        }
    }


    int i=1,d=0,j;
    while(i<j){
        for(j=x;j>i;j--){
            if(a[i]!=a[j]){
                if(a[i]!=v){
                    a[i]=v;
                    d++;
                }
                if(a[j]!=v){
                    a[j]=v;
                    d++;
                }
            }
            i++;
        }
    }
printf("%c %c",a[i],a[x])
     printf("%d",d);


    return 0;
}
