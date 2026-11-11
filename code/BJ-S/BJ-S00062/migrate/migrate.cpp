#include<bits/stdc++.h>
using namespace std;
int c,t,n,x[2000006],d,cnt,ans,minn;
void check(int a){
    if(a==minn)
        cnt++;
    else if(a<minn)
        cnt=0,minn=a;
}
void dfs(int s,int p,int g){
    if(p==g){
        check(s);
        return;
    }
    for(int i=1;i<=d;i++){
        int l=1,r=n,mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(x[mid]>p+i)
                r=mid-1;
            else
                l=mid;
        }
        if(p+i==l)
        dfs(s+1,p+i,g);
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++)
            cin >> x[i];
        cnt=0,ans=0,minn=1e9;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                dfs(1,x[i],j);
        if(cnt==2)  ans++;
        cout << ans;
    }
    return 0;
}
