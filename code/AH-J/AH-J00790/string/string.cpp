#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100005];
char c[100005];
bool flag;
map<char,int>mp;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=2;i<=n;i++){
        if(c[i]!=c[i-1])flag=0;
    }
    if(flag){
        cout<<0;
        return 0;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(a[1],a[2]);
        return 0;
    }else{
        int cnt=0;
        for(int i=1;i<=n/2;i++){
            if(c[i]!=c[n-i+1])cnt+=a[i];
        }
        cout<<cnt;
    }
    return 0;
}
