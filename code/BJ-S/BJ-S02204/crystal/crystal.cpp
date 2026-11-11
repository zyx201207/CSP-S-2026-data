#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,cnt,ans;
    bool p=1;
    long long m;
    long long l1,l2;
    cin>>n>>m;
    cin>>l1>>l2;
    long long c=l2-l1;
    ans=1;
    cnt=1;
    while(p==1){
        if(m>=cnt*c){
            m-=cnt*c;
            ans++;
        }
        else{
            p=0;
        }
        cnt++;
    }
    cout<<ans;
    return 0;
}
