#include<bits/stdc++.h>
using namespace std;
longlong n,cnt,l=0,r,ans=0,temp;
string s,a;
int main{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin n;
for(int i=0,i<=n,i++){
    s+=a;
    cnt++;
}
    r=cnt;
    whle(l<r){
        if(s[l]/=s[r]){
            ans++;
        }
        l++;
        r++;

    }
    cout<<ans;
return 0;
}
