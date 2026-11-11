#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m;
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int>a(n,0);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end(),cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
