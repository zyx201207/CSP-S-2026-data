#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long cnt[N];
void solve1(){//A
    int ans=0;
    for(int i=1;i<=n;i++){
        if((i*(i-1)/2)<=m)ans=i;
    }
    cout<<ans;
}
void solve2(int k){//B
    int ans=0;
    for(int i=1;i<=n;i++){
        if((k*(i*(i-1)/2))<=m)ans=i;
    }
    cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag1=true,flag2=true;
    cin>>a[1];
    if(a[1]!=1)flag1=false;
    long long k=0,y=0;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        k=a[i]-a[i-1];
        if(i==2)y=k;
        if(k!=y)flag2=false;
        if(a[i]!=i)flag1=false;
    }

    if(flag1){
        solve1();
        return 0;
    }
    else if(flag2){
        solve2(k);
        return 0;
    }

    else {
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt[j]+=a[j]-a[i];
            }
            if(cnt[i]<=m){
                ans=max(ans,i);
            }
        }
        cout<<ans;
        return 0;
    }
}
/*
5 5
1 2 4 8 9
1 2 3 4 5
5 6
1 3 5 7 9
5 8
-3 -1 2 2 7
*/
