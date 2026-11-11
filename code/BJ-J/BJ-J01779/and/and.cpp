#include<bits/stdc++.h>
using namespace std;
long long ma=0,h,c,n,m,d[200005],a[200005];
long long book[1048579];
void dfs(int step){
    //cout<<step<<endl;
    if(step==m+1){
        long long ans=d[1];
        for(int i=2;i<step;i++)ans&=d[i];
        ma=max(ma,ans);
        return ;
    }
    for(int i=h+c;i<=n;i++){
        if(book[a[i]]!=0){
            book[a[i]]--;
            d[step]=a[i];
            h=i,c=book[a[i]];
            dfs(step+1);
            book[a[i]]++;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],book[a[i]]++;
    sort(a+1,a+n+1);
    dfs(1);
    cout<<ma;
return 0;
}
