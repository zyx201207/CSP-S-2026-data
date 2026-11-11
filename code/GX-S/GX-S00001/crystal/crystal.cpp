#include<bits/stdc++.h>
using namespace std;
struct Int{
    int sum;
    int x;
}s[5000010];
long long n,m;
long long a[5000010];
long long ans;
bool cmp(Int x1,Int y){
    if(x1.sum==y.sum)return x1.x<=m||y.x<=m;
    else{
        return x1.sum>y.sum;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i]+=1;
            s[a[i]].sum++;
            s[a[i]].x+=j;
        }
    }
    sort(s+1,s+n+1,cmp);
    cout<<s[1].sum;
    return 0;
}
