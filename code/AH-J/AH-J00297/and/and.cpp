#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[10000005];
bool cmp(int x,int y){
    return x>y;
}
void pd(int c,int sum,int f,int cnt){
    if(c==n+1){
        if(cnt==m){
            maxn=max(maxn,sum);
        }
        return ;
    }
    int l=sum;
    if(f==0){
        sum=a[c];
    }
    pd(c+1,(sum&a[c]),f+1,cnt+1);
    sum=l;
    pd(c+1,sum,f,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    pd(1,1,0,0);
    cout<<maxn;
    return 0;
}
