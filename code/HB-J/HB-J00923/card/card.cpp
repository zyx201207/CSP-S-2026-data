#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    map<int ,int>mp;
    map<int ,int>mpp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            mp[a[j]]++;
            if(mp[a[j]]!=1){
                    int k;
            for(int po=i;po<j;po++){
                if(a[po]==a[j]){
                    k=a[po];
                }

            }
                for(int p=k;p<=m;p++){
                    mp[p]=0;
                }
                for(int po=i;po<k;po++){
                    mp[a[po]]++;
                }
            }
            mp[a[j]]++;
        }
        for(int i1=1;i1<=m;i1++){
            if(mp[i1]!=0){
            mp[i1]=0;
            mpp[i1]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mpp[i]<<" ";
    }
    return 0;
}
