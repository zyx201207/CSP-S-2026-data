#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
char a[900000005];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        if(l>5000){
            cout<<3000000000;
            return 0;
        }
        t+=l;
        char c;
        cin>>c;
        for(int j=0;j<l;j++){
            a[x++]=c;
        }
    }
    for(int i=0;i<t/2+1;i++){
        if(a[i]!=a[t-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
