#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],d[500005];
long long ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        d[i]=a[i]-a[i+1];
    }
    bool flag=true;
    for(int i=1;i<n;i++){
        if(d[i]!=d[i+1]){
            flag=false;
            break;
        }
    }
    if(flag){
        long long k=a[2]-a[1];
        int i=1;
        while(m>=0){
            m=m-(k*i);
            i++;
            if(m<0)break;
            ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int j=1;j<n;j++){
        int i=j;
        long long res=1,m1=m;
        while(m1>=0&&i<n){
            m1+=d[i]*(i-j+1);
            i++;
            if(m1<0)break;
            res++;
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}