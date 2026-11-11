#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ma=-1;
long long a[200010];
void f(int i,long long s,int cnt){
    if(cnt==m){
        ma=max(ma,s);
        return;
    }
    for(;i<=n;i++){
        f(i+1,s&a[i],cnt+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)f(i+1,a[i],1);
    cout<<ma;
}
