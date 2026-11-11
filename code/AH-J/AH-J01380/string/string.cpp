#include<bits/stdc++.h>
using namespace std;
long long a[200005],t1[150],t2[150];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,s=0,ans=0;
    string t="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            t+=c[i];
        }
    }
    int l=0,r=t.size()-1,cnt=0;
    while(l<=r){
        if(t[l]!=t[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}
