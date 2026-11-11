#include <bits/stdc++.h>
using namespace std;
long long a,l1,cnt;
int n;
char c;
string s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(int j=1;j<=a;j++){
            s1[l1++]+=c;
        }
    }
    l1--;
    for(int i=0;i<l1/2;i++){
        if(s1[i]!=s1[l1-i-1]) cnt++;
    }
    cout << cnt;
    return 0;
}
