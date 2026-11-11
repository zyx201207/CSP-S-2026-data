#include <bits/stdc++.h>
using namespace std;
int a[1000000],ans=0;
string s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int gs;
        string a;
        cin>>gs>>a;
        if(gs>mx)mx=gs;
        for(int i=1;i<=gs;i++){
            s+=a;
        }
    }
    ans=0;
    cout<<ans;
    return 0;
}

