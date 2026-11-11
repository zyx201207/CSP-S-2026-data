#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];
string s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> c[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s += c[i];
        }
    }

    int l=s.size(),cnt=0;
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) cnt++;
    }
    cout << cnt;

    return 0;
}
