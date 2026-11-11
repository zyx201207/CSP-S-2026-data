#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=1,x=1,y=1;
    while(m>0){
        if(m>x) {
            m-=x;
            ans++;
            x++;
        }
        else{
            break;
        }
        if(m>y){
            m-=y;
            ans++;
            y++;
        }
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}