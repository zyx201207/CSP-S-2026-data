#include<bits/stdc++.h>
using namespace std;
long long n,a,mid=0,ans=0,b=0,s;
string r,q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>q;
        for(int j=0;j<a;j++){
            r+=q;
        }
    }
    s=r.size();
    if(n%2==0) mid=s/2-1;
    else mid=s/2;
    while(s-1>mid){
        if(r[b]!=r[s-1]) ans++;
        b++;
        s--;
    }
    cout<<ans;
    return 0;
}
