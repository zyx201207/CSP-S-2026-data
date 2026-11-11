#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c[200005],sum,cnt,ans;
char ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch;
        c[i]=ch-'a'+1;
        sum+=a[i];
    }
    cnt=sum/2;
    int l=1,r=n;
    while(cnt){
        if(l==r)    break;
        long long mi=min(a[l],a[r]);
        a[l]-=mi;
        a[r]-=mi;
        if(c[l]!=c[r])  ans+=mi;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
        cnt-=mi;
        //cout<<cnt<<" "<<l<<" "<<r<<endl;
    }
    cout<<ans;
    return 0;
}
