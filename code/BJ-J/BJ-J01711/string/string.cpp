#include<bits/stdc++.h>
using namespace std;
int n;
void func(){
    long long ans=0;
    string ss;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            ss+=b;
        }
    }
    for(int i=0;i<ss.size()/2;i++){
        if(ss[i]!=ss[ss.size()-1-i])ans++;
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    func();
    return 0;
}
