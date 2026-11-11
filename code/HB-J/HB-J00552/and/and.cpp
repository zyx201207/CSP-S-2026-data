#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool b[200005];
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=30;j>=0;j--){
        int num=0;
        for(int i=1;i<=n;i++){
            if(b[i])continue ;
            num+=(((1<<j)&a[i])!=0);
        }
        if(num>=m){
            ans|=(1<<j);
            for(int i=1;i<=n;i++){
                if(!((1<<j)&a[i]))b[i]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
