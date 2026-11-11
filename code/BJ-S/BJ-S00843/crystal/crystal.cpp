#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500001]={};
    int ans[500001]={};
    int ansmax=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[j]-a[i]==0) ans[i]+=1;
                if(a[j]-a[i]<=m/n&&a[j]-a[i]>0) ans[i]+=1;
            }
    }
    for(int i=0;i<n;i++){
        if(ansmax<ans[i]) ansmax=ans[i];
    }
    cout<<ansmax;
    return 0;
}