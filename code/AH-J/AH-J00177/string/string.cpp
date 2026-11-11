#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k,cnt=0;
    string s="",c;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> k >> c;
        for(int j=1;j<=k;j++)s=s+c;
    }for(int i=1;i<=s.size()/2;i++){
        if(s[i-1]!=s[s.size()-i])cnt++;
    }cout << cnt;
    return 0;
}
