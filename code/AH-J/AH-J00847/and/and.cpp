#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
int t[35];
void f(int x){
    if(x==0)return;
    for(int i=0;i<=30;i++){
        t[i]+=x%2;
        x=x/2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        f(a[i]);
    }
    long long cnt=0,w=1;
    if(t[0]>=m)cnt++;
    for(int i=1;i<=30;i++){
        w=1;
        if(t[i]>=m){
            for(int j=0;j<i;j++){
                w*=2;
            }
            cnt+=w;
        }
    }
    cout<<cnt;
    return 0;
}
