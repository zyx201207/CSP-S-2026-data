#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int num;
    char let;
}a[200001];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].let;
        for(int j=cnt+1;j<=cnt+a[i].num;j++){
            s+=a[i].let;
        }
        cnt+=a[i].num;
    }
    int mid=(cnt%2==0)?(cnt/2):(cnt/2+1);
    int ans=0;
    for(int i=mid;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]) ans++;
    }
    cout<<ans;





    return 0;
}
