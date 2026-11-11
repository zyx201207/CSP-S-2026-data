#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],A,B;
vector<long long>v[200010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    sort(a+1,a+n+1,cmp);
    int mi=a[1];
    for(int i=1;i<=m;i++){
        if(a[i]<mi)mi=a[i];
    }
    cout<<mi;
    return 0;
}
