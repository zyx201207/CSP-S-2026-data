#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m;
int w[N],p[N];
bool cmp(int x,int y){
    return x>y;
}
string s[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=1;i<=m;i++){
        ans=max(ans,ans&a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
