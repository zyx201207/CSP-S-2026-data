#include<bits/stdc++.h>
using namespace std;
int n,m;
int dd(int x,int a,int *c){
    for(int i=x;i>=0;i--){
        if(c[i]==a)
            return i;
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    int a[n],b[m+1],c[n];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        memset(c,0,sizeof(c));
        int x=0;
        for(int j=i;j<n;j++){
            int t=dd(x,a[j],c);
            if(j!=i && x!=0 && t!=-1){
                memset(c+t,0,sizeof(c));
                x=t;
            }
            c[x]=a[j];
            x++;
        }
        int j=0;
        while(c[j]!=0){
             b[c[j]]++;
             j++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",b[i]);
    return 0;
}
