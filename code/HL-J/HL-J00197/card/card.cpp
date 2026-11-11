#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+2;
int cnt1[N],cnt2[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    vector<int>v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.push_back(x);
    } v.push_back(0);
    reverse(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
        if(v[i]==1) cnt1[i]++;
        else cnt2[i]++;
    }
    if(v[1]==1){
        cout<<n;
        cout<<' ';
        cout<<n/2;
    }
    else{
        cout<<n/2<<' '<<n;
    }
    return 0;
}
