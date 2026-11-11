#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    long long arr[1000000]={};
    long long s[10000000]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int k=n;
    while(k>0){
        long long a[1000000]={};
        for(int i=1;i<=m;i++){
            for(int j=1;j<=k;j++){
                if(arr[j]==m){
                   a[m]++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(a[m]%2==0){
                s[a[m]]++;
            }
        }
        k--;
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }


    return 0;
}
