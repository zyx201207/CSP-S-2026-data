#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005][35];
void f(int in,int num){
    int ind=31;
    while(num!=0){
        a[in][ind--]=num%2;
        num=num/2;
    }
}
int v[200005];
int b[200005];
int bin=1;
int F=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        f(i,x);
    }
    for(int i=1;i<=31;i++){
        if(F==0){
            int num=0;
            for(int j=1;j<=n;j++){
                if(a[j][i]==1&&v[j]!=-1){
                    num++;
                }
            }
            if(num>m){
                for(int j=1;j<=n;j++){
                    if(a[j][i]==0) v[j]=-1;
                }
                a[n+1][i]=1;
            }
            else if(num<m) a[n+1][i]=0;
            else{
                F=1;
                for(int j=1;j<=n;j++){
                    if(a[j][i]==1&&v[j]!=-1) b[bin++]=j;
                }
                break;
            }
        }
    }
/*    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=31;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    if(bin>1){
/*        cout<<endl<<endl<<bin<<endl<<endl;
        for(int i=1;i<bin;i++) printf("%d ",b[i]);
        cout<<endl;*/
        for(int i=1;i<=31;i++){
            int num=1;
            for(int j=1;j<bin;j++){
                num=num&a[b[j]][i];
            }
            a[n+1][i]=num;
        }
    }
    long long num=0;
    long long p=1;
    for(int i=31;i>=1;i--){
        num=num+a[n+1][i]*p;
        p=p*2;
    }
 /*   cout<<endl<<"b:";
    for(int i=1;i<bin;i++) cout<<b[i]<<" ";
    cout<<endl;*/
    printf("%lld",num);
    return 0;
}
