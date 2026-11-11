#include <bits/stdc++.h>
using namespace std;
int n,x=0;
string s[10010],h[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i]>>h[i];
        if(s[1]!=s[n]&&s[2]!=s[n-1]&&s[3]!=s[n-2]&&s[4]!=s[n-3]){
            x++;
        }
    }
    cout << x;
    return 0;
}
