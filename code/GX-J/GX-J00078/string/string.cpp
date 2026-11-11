#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;

struct node{int i;string x;};
vector <int> shu;
vector <string> s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int j=0;
    for (int i=0;i<n;i++){
        int x;
        string y;
        cin>>x>>y;
        j+=x;
        shu.push_back(j);
        s.push_back(y);
    }
    //for (int i=0;i<n;i++) cout<<shu[i]<<' ';cout<<endl;
    //cout<<endl<<a<<endl;
    int ans=0;
    for (int i=0;i<j/2;i++){
        int l=i,r=j-i-1;
        int lq=lower_bound(shu.begin(),shu.end(),l+1)-shu.begin();
        int rq=lower_bound(shu.begin(),shu.end(),r+1)-shu.begin();
        //cout<<endl<<l<<' '<<r<<':'<<lq<<' '<<rq<<';'<<s[lq]<<' '<<s[rq]<<endl;
        if (s[lq]!=s[rq]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
