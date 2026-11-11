#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        cin>>c[i];
    }int need  =0;
    string s  = "";
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            s+=c[i];
        }
    }
    string d = s;
    reverse(s.begin(),s.end());
    long long len = s.size()-1;
    for(int i = 0;i <=len;i++){
        if(d[i] != s[i]) need++;
    }
    cout<<need/2;



    return 0;
}
