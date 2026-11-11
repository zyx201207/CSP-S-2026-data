#include<bits/stdc++.h>
using namespace std;
queue<string>s;
int main(){
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    int n,a[200010]={},b[200010]={},ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];i++){
            s.push_back(b[i]);
        }
    }
    for(int i=1;i<=s.size();i++){
        if(s.size()%2==0){
            if(s[i]!=s[2*(s.size()/2-i)]{
                s[i]=s[2*(s.size()/2-i)];
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}