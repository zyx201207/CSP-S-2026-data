#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,i,j,cnt=0,sum=0;
    char t;
    string s;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a;
        cin>>t;
        for(j=1;j<=a;j++){
            s=s+t;
        }
        sum=sum+a;
    }
    i=sum-1;
    j=0;
    while(i>=j){
        if(s[i]!=s[j]){
            cnt++;
        }
        i--;
        j++;
    }
    cout<<cnt;
    return 0;
}
