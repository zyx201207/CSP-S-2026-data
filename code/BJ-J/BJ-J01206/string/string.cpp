#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="*";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    int l=s.size()-1,ans=0;
    for(int i=1;i<=l/2;i++){
        if(s[i]!=s[l-i+1])ans++;
    }
    cout<<ans;
    return 0;
}
