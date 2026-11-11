#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int m;
    int l=0;
    int cnt=0;
    int an[1000000];
    cin>>n>>m;
    int r=n;
    int mid=(l+r)/2;
    for(int i=1;i<=n;i++){
        cin>>i;
        an[i]=n;
    }
    for(int k=1;k<=r;k++){
        if(an[k]>an[k+1]){
            an[k],an[k+1]=an[k+1],an[k];
        }
    }
    for(int j=0;j<n;j++){
        an[j]++;
        if(an[j]!=an[j+1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}