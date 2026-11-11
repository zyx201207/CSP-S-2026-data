#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0)+clock());
int n;
int m;
int a[200005];
int p[200005];
bool cmp(int x,int y){
    return __builtin_popcount(x)>__builtin_popcount(y) || ((__builtin_popcount(x)==__builtin_popcount(y) && rng()%1000000000>rng()%1000000000));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int start=clock();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // int t=a[i];
        // while(t){
        //     t>>=1;
        //     b[i]++;
        // }
    }
    if(n<=10){
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
        int ans=0;
        do{
            int sum=a[p[1]];
            for(int i=2;i<=m;i++){
                sum&=a[p[i]];
            }
            ans=max(ans,sum);
        }while(next_permutation(p+1,p+1+n));
        cout<<ans<<endl;
        return 0;
    }
    int res=0;
    while(clock()-start<0.8*CLOCKS_PER_SEC){
        sort(a+1,a+1+n,cmp);
        int ans=a[1];
        for(int i=2;i<=m;i++){
            ans&=a[i];
        }
        res=max(res,ans);
    }
    cout<<res<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200005];
bool cmp(int x,int y){
    return __builtin_popcount(x)>__builtin_popcount(y) || (__builtin_popcount(x)==__builtin_popcount(y) && x>y);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
*/