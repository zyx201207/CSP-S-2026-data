#include <iostream>
using namespace std;
const int N=200005;
int n,a[N],ans;
char c[N];
string s="";
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i] >> c[i];
        for (int j=1;j<=a[i];j++) s+=c[i];
    }
    for (int i=0;i<s.size();i++) ans+=(s[i]==s[s.size()-i-1]);
    cout <<ans;
    return 0;
}
