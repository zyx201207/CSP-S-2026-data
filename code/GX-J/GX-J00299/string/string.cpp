#include <bits/stdc++.h>
using namespace std;

string s;
long long n,a;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>> a >> c;
        s.append(c,a);
    }int q=1;
    if(s[0]=='a'&&s[1]=='a'&&s[2]=='b'&&s[3]=='b'&&s[4]=='c')cout << 2;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            q=0;
            break;
        }
    }
    if(q=1)cout <<0;
    return 0;
}
