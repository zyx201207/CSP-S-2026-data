#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string c,s="";
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x>>c;
        cnt+=x;
        while(x--){
            s+=c;
        }
    }
    long long half=cnt/2,ans=0;
    for(int i=0;i<half;i++){
        if(s[i]!=s[cnt-i-1]){
//            cout<<s[i]<<" "<<s[cnt-i-1]<<"\n";
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
