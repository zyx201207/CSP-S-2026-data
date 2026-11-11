#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],d[N],ans=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++){
        long long now=1,sum=0,num=1;
        bool f=0;
        for(int j=i;j<n;j++){
            if(sum+now*d[j]<=m){
                sum+=now*d[j];
                num++;
                now++;
            }else{
                f=1;
                break;
            }
        }
        ans=max(ans,num);
        if(!f)   break;
    }
    cout<<ans;
    return 0;
}
