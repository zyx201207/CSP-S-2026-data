#include<bits/stdc++.h>
using namespace std;
long long lis[200005],m,n,ans=0;
bool cmp(long long a,long long b){
    return a<b;
}
int main(){
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(long long i=1;i<=m;i++){
        cin>>lis[i];
    }
    sort(lis+1,lis+m+1,cmp);
    ans=lis[m-n+1];
    cout<<ans;
    return 0;
}
