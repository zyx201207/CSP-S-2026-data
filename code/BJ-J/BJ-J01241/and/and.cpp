#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],m;
long long ans,sum,u;
void note(long long x,long long t){
    if(t==0){
        ans=max(ans,sum);
        sum=0;
        return ;
    }
    if(n-x+1>t){
        note(x+1,t);
    }
    if(sum==0&&t==m){
        sum=a[x];
    }else{
        sum=sum&a[x];
    }
    note(x-1,t-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            u=max(u,a[i]);
        }
        cout<<u;
    }else{
        note(1,m);
        cout<<ans;
    }
    return 0;
}
