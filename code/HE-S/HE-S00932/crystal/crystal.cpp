#include<bits/stdc++.h>
using namespace std;
#define MAX 500010
long long n,m,a[MAX],cha,ans;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    int w=1;
    while(m>=0){
        cha=a[w]-a[w-1];
        m-=cha*w;
        w++;
    }
    cout<<w-1;
    return 0;
}
