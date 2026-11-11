#include<bits/stdc++.h>
using namespace std;
int tong[300005],a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--){
        if(tong[a[i]]!=0){
            for(int j=0;j<m;j++){
                if(tong[j]>=i)tong[j]=0;
            }
        }
        else tong[a[i]]=i;
        for(int j=0;j<m;j++){
            if(tong[j]>0)ans[j]++;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i];
    return 0;
}
