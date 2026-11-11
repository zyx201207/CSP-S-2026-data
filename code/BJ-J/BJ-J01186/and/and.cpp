#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt=0,maxn=0;
    cin>>n>>m;
    int a[200005]={},qzh[200005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    cnt=a[i]&a[j];
                    maxn=max(maxn,cnt);
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(n<=20){
        int q[25]={},cnt=-1;
        for(int i=n;i>=n-m+1;i--)q[i]=1;
        while(next_permutation(q+1,q+n+1)){
            for(int i=1;i<=n;i++){
                if(q[i]){
                    if(cnt==-1){
                        cnt=a[i];
                    }
                    else cnt&=a[i];
                }
            }
            maxn=max(maxn,cnt);
            cnt=-1;
        }
        cout<<maxn;
        return 0;

    }
    sort(a+1,a+n+1);
    cout<<(n-m);
    return 0;

}
