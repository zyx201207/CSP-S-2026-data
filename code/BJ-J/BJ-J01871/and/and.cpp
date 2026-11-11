#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+9;
int n,m,a[N],b[N],cnt,ans;
bool cmp(int x,int y){
    return x>=y;
}
bool f(int x,int y){
    for(int i=0;i<=30;i++){
        if(i==y){
            if(x%2==1)return 1;
            else return 0;
        }
        x/=2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=30,cnt=0;i>=0;i--,cnt=0){
        for(int j=1;j<=n;j++){
            if(f(a[j],i)==1)b[++cnt]=a[j];
        }
        if(cnt>=m){
            ans+=(1<<i),n=cnt;
            for(int j=1;j<=n;j++)a[j]=b[j];
        }
    }
    cout<<ans;
    return 0;
}