#include<bits/stdc++.h>
using namespace std;
int main(){
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s,s2;
    for(int i=1;i<=n;i++){
    int a=0;
    s2.erase(0,1e99);
    cin>>a;
    cin>>s2;
    for(long long i=1;i<=a;i--)s.insert(s.size(),s2)
    }
    cout<<s;
    return 0;
}
