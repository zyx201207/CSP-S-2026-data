#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m;
int a[N];
int mask;
bool cmp(int x,int y){
    return (x&mask)>(y&mask);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    mask=(1<<30);
    while(mask){
        sort(a+1,a+n+1,cmp);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]&mask)cnt++;
        }
        if(cnt>=m){
            while(!(a[n]&mask))n--;
        }
        mask/=2;
    }
    int res=a[1];
    for(int i=2;i<=m;i++)res&=a[i];
    cout<<res<<"\n";
}