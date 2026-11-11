#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005],ans[1000005],r[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int cnt=0,pos=i;
        while(true){
            if(r[a[pos]]>pos){
                ans[a[pos]]++;
                pos=r[a[pos]];
                pos++;
            }
            else{
                ans[a[pos]]++;
                pos++;
            }
            if(pos>n) break;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}



