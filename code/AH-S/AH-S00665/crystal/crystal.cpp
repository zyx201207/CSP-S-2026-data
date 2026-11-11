#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
long long n,m,a[500005],maxn,dccl;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        //cout<<a[i]<<endl;
    }
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            dccl=0;
            break;
        }
        dccl=a[i]-a[i-1];
    }
    //cout<<"dccl:"<<dccl<<endl;
    if(dccl){
        long long ts=m;//m/dccl份
        for(int i=0,j=0,k=0;;){
            if(k>ts){
                cout<<min(i,(int)n);
                return 0;
            }
            i++;
            j+=dccl;
            k+=j;
          // cout<<i<<" "<<j<<" "<<k<<endl;
        }
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        long long sy=m,cnt=0;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=sy){
                sy-=a[i]-a[j];
                cnt++;
            }
            else break;
       //     cout<<"将第"<<j<<"个水晶补到"<<a[i]<<"剩余"<<sy<<endl;
        }
        maxn=max(maxn,cnt+1);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
