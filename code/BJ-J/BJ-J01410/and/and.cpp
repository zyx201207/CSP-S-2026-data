#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],b[N];
long long zdz;
void dfs(int step){
    if(step>=m+1){
        long long cnt=b[1];
        for(int i=1;i<=m;i++)cnt=cnt&b[i];
        zdz=max(cnt,zdz);
        return;
    }
    for(int i=step;i<=n;i++){
        b[step]=a[i];
        dfs(i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            cout<<0;
            return 0;
        }
    }
    if(m==1){
        for(int i=1;i<=n;i++)zdz=max(a[i],zdz);
        cout<<zdz;
    }else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                zdz=max(zdz,a[i]&a[j]);
        cout<<zdz;
    }else if(m==n){
        for(int i=1;i<=n;i++)zdz=zdz^a[i];
        cout<<zdz;
    }else{
        b[1]=a[1];
        dfs(1);
        cout<<zdz;
    }
    return 0;
}