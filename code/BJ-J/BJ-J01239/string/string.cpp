#include<bits/stdc++.h>
using namespace std;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,b;
    char a;
    long long last=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b>>a;
        for(int j=0;j<b;j++){
            c[last+j]=a;
        }
        last+=b;
    }
    for(int i=0;i<last/2+1;i++){
        if(c[i]!=c[last-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
