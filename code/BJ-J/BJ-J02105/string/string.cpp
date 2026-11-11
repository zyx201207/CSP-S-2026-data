#include<bits/stdc++.h>
using namespace std;
int a[20005],m;
int cnt = 0;
char c[20015];
string s1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i = 1;i<=m;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j = 1;j<=a[i];j++){
            s1 +=c[i];
        }
    }
    int l = s.size();
    for(i = 1;i<=i/2;i++){
        if(s[i] != s[l - i - 1]){
            cnt += 1;
        }
    }
    cout<<cnt
    return 0;
}
