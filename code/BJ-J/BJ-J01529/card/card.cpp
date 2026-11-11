#include<bits/stdc++.h>
using namespace std;
const long long MX=5e5+2,Mx=3e5+2;
long long n,m,a[MX],b[Mx],cnt;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]==2){
            cnt++;
            b[a[i]]==0;
        }
    }
    for(long long i=0;i<m;i++){
        cout<<cnt<<" ";
        cnt++;
    }
    return 0;
}