#include<bits/stdc++.h>
using namespace std;

long long n,a,way1,way2;
char c;
bool flag=true;
string s;
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        if(c!=s[0]&&i>1)flag =false;
        for(int j=1;j<=a;j++)s+=c;
    }
    long long len=s.size();
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[len-i-1])way1++;
    }
    if(!flag)
        cout << way1;
    else cout << 0;
    return 0;
}