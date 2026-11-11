#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,n,m[200005],r,l;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n-1;
    for(int i=0;i<n;i++)
        cin>>m[i]>>c[i];
    while(r!=l){
        ll minn=min(m[l],m[r]);
        if(c[l]==c[r]){
            m[l]-=minn;
            m[r]-=minn;
            if(m[l]==0)
                l++;
            if(m[r]==0)
                r--;
        }
        else{
            m[l]-=minn;
            m[r]-=minn;
            ans+=minn;
            if(m[l]==0)
                l++;
            if(m[r]==0)
                r--;
        }
    }
    cout<<ans;
    return 0;
}
