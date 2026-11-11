#include<bits/stdc++.h>
using namespace std;
char a[1000000000]={};
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int o;int m;cin>>m;
    for(int i=1;i<=n;i++){
        char k;
        cin>>k;
        for(int j=0;j<m;j++){
            a[o+j]=k;
        }
        o=m+o;
        if(i==n){
            break;
        }
        cin>>m;


    }
    int ans=0;
    int k=o/2+1;
    for(int i=o/2+1;i<=o;i++){
        if(a[i]!=a[k]) ans++;
        k--;

    }
    cout<<ans;
    return 0;
}

