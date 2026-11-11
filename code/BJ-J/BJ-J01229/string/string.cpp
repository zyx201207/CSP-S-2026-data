#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll a,firstlen,lastlen;//shu'liang   ci'shu
    char c;
}q[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0,len=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].a>>q[i].c;
        q[i].firstlen=len+1;
        len+=q[i].a;
        q[i].lastlen=len;
    }
    ll j=1,pos=1,k=n;
    for(int i=1;i<=len/2;i++){
        if(q[j+1].firstlen==i)   j--;
        if(q[k-1].lastlen==len-i+1)   k--;
        if(q[j].c!=q[k].c)  ans++;
    }
    cout<<ans;
    return 0;
}