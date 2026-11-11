//GZ-J00505 贵阳市第三实验中学 郑傅允
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,ans=0;
    string s="";
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        cnt+=x;
        for(long long j=1;j<=x;j++) s+=c;
    }
    for(int i=1;i<=cnt/2;i++){
        if(s[i]!=s[cnt+1-i]) ans++;
    }
    cout<<ans;
    return 0;
}
