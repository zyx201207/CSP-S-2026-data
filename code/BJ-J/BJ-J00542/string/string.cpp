#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char c[1000005];
    int n,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int A;char C;
        cin>>A>>C;
        int j;
        for(j=cnt;j-cnt<A;) c[++j]=C;
        cnt=j;
    }
    for(int i=1;i<=cnt/2;i++){
        if(c[i]!=c[cnt-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}

