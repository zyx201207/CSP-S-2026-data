#include<bits/stdc++.h>
using namespace std;
char y[3];
int tot=0;
long long ret[200000000];
int gad(LL ret*){
int i=1,j=tot,sum=0;
while(i==j){
    if(ret[i]!=ret[j])sum++;
    i++;
    j--;
}
return sum;
}
int main(){
    freopen("string.in",'r',conin);
    freopen("string.out",'w',conout);
    int n;
    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;i++){
    scanf("%d%s,&x,y);
        for(int j=1;j<=x;j++){
            int ret[tot++]=y-'96';
        }
    }
    printf("%d",sum);
    return 0;
}
