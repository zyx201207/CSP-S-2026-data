#include<cstdio>
using namespace std;
int n,m;
int in[500009],ls;
FILE*p;
int main(){
    p=freopen("card.in","r",stdin);
    p=freopen("card.out","w",stdout);
    ls=scanf("%d %d",&n,&m);
    int i;
    for(i=0;i<n;i++){
        ls=scanf("%d",in+i);
    }
    //with special:A
    int benum=1;
    int sum=0;
    for(i=0;i<n;i++){
        if(in[i]!=benum){
            printf(" %d",sum);
            benum=in[i];
        }
        sum++;
    }
    printf(" %d\n",sum);
    return 0;
}