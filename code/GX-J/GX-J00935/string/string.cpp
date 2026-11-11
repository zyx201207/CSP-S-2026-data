
#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,k=0;
char b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        for(int j=1;j<=a;j++){
            s+=b;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            k++;
            s[s.size()-1-i]=s[i];
        }
    }
    cout << k;
    return 0;
}
