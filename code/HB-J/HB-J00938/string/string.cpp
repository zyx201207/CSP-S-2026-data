#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
string s=" ";
long long L=0,a[maxn],l[maxn],r[maxn];
char c[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l[i]=L+1;
        r[i]=L+a[i];
        L+=a[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
        if(i>1&&c[i]!=c[i-1]) f=false;
    }
    long long mid=L/2;
    if(f){
        cout<<0;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<=mid;i++){
        ans+=(s[i]!=s[L-i+1]);
    }
    cout<<ans;
    return 0;
}
