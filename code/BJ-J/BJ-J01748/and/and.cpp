#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,mx=0,a[200010],sum=0,m;
    cin>>n>>m;
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        sum=a[1];
        for(int i=2;i<=n;i+=1){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        for(int l=1;l<=n;l+=1){
            long long ans=0;
            if(l==n-1){
                ans=a[1];
            }
            else{
                ans=a[l+1];
            }
            for(int i=1;i<=n;i+=1){
                if(i==l){
                    int aaa;
                }
                else{
                    ans&=a[i];
                }
            }
            sum=max(sum,ans);
        }
        cout<<sum;
        return 0;
    }
    for(int i=1;i<=n;i+=1){
        long long ans=0;
        ans=a[i];
        for(int k=i;k<=m+i-1;k+=1){
            ans&=a[k];
        }
        sum=max(sum,ans);
        ans=a[i];
        for(int k=i;k<=(m+i-2)*2;k+=2){
            ans&=a[k];
        }
        sum=max(sum,ans);
    }
    cout<<sum;
}
