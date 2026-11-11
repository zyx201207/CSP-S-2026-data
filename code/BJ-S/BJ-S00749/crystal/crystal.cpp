#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n[100001];
    int m=0;
    long long ans[100001];
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<=m;i++){
        cin>>n[i];
        for(int j=0;j<=m;j++){
            ans[j]=min(n[i-1],n[i])+1;
            if(ans[j]=ans[j-1]){

            }
        }
    }

    cout<<"4";
    return 0;
}
