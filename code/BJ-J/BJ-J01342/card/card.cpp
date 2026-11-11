#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000000],tong[1000000],mp[1000000],ans[1000000];
string s;
bool checkA;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]<a[i-1]) checkA=1;
    }
    if(!checkA){
        for(int i=1;i<=n;i++){
            mp[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<mp[i]<<" ";
        }
        return 0;
    }
    return 0;
}
