#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],ans=0,x;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        b[i]=c-'a'+1;
        if(b[i]==b[i-1]){
            n-=1;
            a[i-1]+=a[i];
            i--;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(b[n-i+1]!=b[i]){
            b[n-i+1]=b[i];
            if(n-i+1!=i+1){
                a[n-i+1]=a[i];
                a[n-i]-=a[i]-a[n-i+1];
                ans+=(a[n-i+1]+a[i]-a[n-i+1]);
            }
            else ans+=a[n-i+1];
        }
        if(i==n-i+1||i+1==n-i+1)break;
    }
    cout<<ans;
    return 0;
}
//RP++
//CCF help me work out the third text
//Maoxiaojiou help me RP++
//Maobailing help me RP++
