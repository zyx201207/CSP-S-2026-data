#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200010]={},ab[200010]={};
    string b[200010];
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(int i=0;i<n;i++)
        ab[i]=a[i];
    long long a1=0,b1=n-1;
    long long ans=0;
    for(;1;){
        int mi=min(a[a1],ab[b1]);
        if(a[a1]==0)
            a1++;
        if(ab[b1]==0)
            b1--;
        if(a1==n||b1==-1) break;
        if(b[a1]!=b[b1]) ans+=mi;
        a[a1]-=mi;ab[b1]-=mi;
    }
    cout<<ans/2;
    return 0;
}
