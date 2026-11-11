#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,cnt=0,flag=1;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];

    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        b[i-1]=a[i]-a[i-1];
    }
    sort(b,b+n);
    int cmp=1;
    for(int i=1;i<n;i++){
        if(b[i]==0){
            continue;
        }
        cnt+=(b[i]*cmp);
        if(cnt==m){
            cout<<cmp+1<<endl;
            return 0;
        }else if(cnt>m){
            cout<<cmp<<endl;
            return 0;
        }
        cmp++;
    }
    return 0;
}
