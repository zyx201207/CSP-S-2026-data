#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long pre[200005];
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        pre[i]=a[i]+pre[i-1];
    }
    long long len=pre[n],r=pre[n],ans=0;
    if(len<100000000){
        string ss="";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                ss=ss+s[i];
            }
        }
        int cnt=0;
        for(int i=0;i<=(len-1)/2;i++){
            if(ss[i]!=ss[len-i-1]) cnt++;
        }
        cout<<cnt;
        return 0;
    }
    int j=n;
    for(int i=1;pre[i]<=len/2;i++){
        while(j>=i&&pre[n]-pre[j-1]<=pre[i]){
            //cout<<'b'<<' ';
            if(s[i]!=s[j]){
                ans+=min(r,pre[j])-pre[j-1];
                //cout<<'a'<<' ';
            }
            j--;
            //cout<<i<<' '<<j<<' '<<ans<<'\n';
        }
        if(s[i]!=s[j]){
            //cout<<'c'<<i<<' '<<j<<' '<<s[i]<<' '<<s[j]<<'\n';
            ans+=pre[i]-(pre[n]-pre[j]);
        }
        r=pre[n]-pre[i];
        //cout<<r<<' '<<i<<' '<<j<<' '<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
