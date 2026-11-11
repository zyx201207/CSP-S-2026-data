#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],tong[M],ans[M];
void A(int s){
for(int i=s;i<=n;i++){
    tong[a[i]]++;
    if(tong[a[i]]>1){
        for(int j=i-1;j>=s;j--){
            tong[a[j]]-=1;
            if(a[j]==a[i])break;
        }
    }
}
for(int i=1;i<=m;i++){
    if(tong[i]==1)ans[i]+=1;
    tong[i]=0;
}
return;
}
signed main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
    A(i);

}
for(int i=1;i<=m;i++){
    cout<<ans[i]<<" ";
}

return 0;
}
