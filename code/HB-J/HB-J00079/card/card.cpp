#include<bits/stdc++.h>
#define ll long Long
using namespace std;
    vector<int> kadui(500005);
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,newinsert;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans[m]={0};
    for(int i=0;i<n-1;i++){
        //m
        newinsert=i;
        for(int j=i;j<n;j++){
            kadui[newinsert]=a[j];
            for(int k=newinsert;k>j;k--){
                if(kadui[k]=kadui[newinsert]){
                    newinsert=k;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
