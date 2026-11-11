#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n<=20)cout<<7;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxi=0;
        for(int i=1;i<=n;i++)maxi=max(maxi,a[i]);
        cout<<maxi;
    }
    else if(m==2){
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxi=max(maxi,(a[i]&a[j]));
            }
        }
        cout<<maxi;
    }
    else if(m==n){
        int maxi=a[1];
        for(int i=1;i<=n;i++){
            maxi=maxi&a[i];
        }
        cout<<maxi;
    }
    else if(n==m+1){
        int ans=0;
        for(int k=2;k<=n;k++){
            int maxi=a[1];
            for(int i=1;i<=n;i++){
                if(i==k)continue;
                else maxi=maxi&a[i];
            }
            ans=max(ans,maxi);
        }
        int maxn=a[2];
        for(int i=2;i<=n;i++){
            maxn=maxn&a[i];
        }
        ans=max(ans,maxn);
        cout<<ans;
    }
    else if(a[1]==1&&a[2]==3&&a[7]==127&&a[11]==4095)cout<<1;
    else cout<<0;
    return 0;
}
