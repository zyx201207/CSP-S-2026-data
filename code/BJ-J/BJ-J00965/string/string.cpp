#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,cnt;
char s[100000005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=0;i<a;i++){
            s[i+cnt]=c;
        }
        cnt+=a;
    }
    int ans=0;
    if(cnt%2==0){
        int mid=cnt/2;
        for(int i=0;i<mid;i++){
            if(s[i]!=s[cnt-1-i]){
                ans++;
            }
        }
    }
    else{
        int mid=cnt/2;
        for(int i=0;i<=mid;i++){
            if(s[i]!=s[cnt-1-i]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
