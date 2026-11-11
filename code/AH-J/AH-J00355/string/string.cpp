#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a;
char b;
string s1;
string s2;
int cnt;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        m+=a;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s1=s1+b;
        }
    }
    for(int i=m-1;i>=0;i--){
        s2=s2+s1[i];
    }
    int l=m/2;
    for(int i=0;i<l;i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
