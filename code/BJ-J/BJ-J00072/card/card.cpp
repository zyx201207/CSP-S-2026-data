#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
void solve1(){
    int pos=a[1];
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]) cnt++;
        else{
             cnt++;
             cout<<cnt<<" ";
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag) solve1();
    return 0;
}
