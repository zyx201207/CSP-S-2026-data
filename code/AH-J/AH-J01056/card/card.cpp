#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[300005],a[300005],s[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    while(n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(s[i]==a[j]){
                    cnt=j-1;
                    break;
                }
            }
            cnt++;
            a[cnt]=s[i];
        }
        for(int j=1;j<=cnt;j++){
            t[a[j]]++;
        }
        n--;
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
