#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],t[10000010];
void solve(int x){
    long long s[1000010];
    for(int i=x;i<=n;i++){
        s[i-x+1]=a[i];
    }
    for(int i=1;i<=n-x;i++){
        for(int j=i+1;j<=n-x+1;j++){
            if(s[i]==s[j]&&s[i]!=-1){
                for(int x=i;x<j;x++){
                    s[x]=-1;
                }
            }
        }
    }
    for(int i=1;i<=n-x+1;i++){
        if(s[i]!=-1){
            t[s[i]]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
