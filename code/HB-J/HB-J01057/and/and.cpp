#include<bits/stdc++.h>
using namespace std;
long long ans=LLONG_MIN;
long long num[100005];
bool use[100005];
long long bfs(int n,int num){
    long long  re=LLONG_MAX;
    long long maxx=LLONG_MIN;
    if(!num){
        return re;
    } else  if(!n&&num){
        return 0;
    }else {
        for(int i=0;i<n;i++){
            use[i]=1;
            if(!use[i]){
                maxx=(bfs(n,num)>(num[i]|bfs(n,num-1))?bfs(n,num):(num[i]|bfs(n,num-1)));
            }
            use[i]=0;
        }
        return maxx;
    }
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",bfs(a,b));
    return 0;
}
