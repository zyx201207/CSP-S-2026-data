
#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n, cnt=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        int m;
        string c;
        cin >> m;
        cin >> c;
        for(int j=1;j<=m;j++){
            s += c;
        }
    }
    int x=s.size();
    for(int i=0;i<x/2;i++){
        if(s[i] != s[x-i-1]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
