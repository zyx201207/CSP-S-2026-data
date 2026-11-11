#include <bits/stdc++.h>
using namespace std;
long long n,a,l,cnt;
string s1="",s2="";
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s1+=c;
        }
        l+=a;
    }
    int z=l%2;
    for(int i=0;i<l/2+z;i++)s2+=s1[i];
    for(int i=l/2-1;i>=0;i--)s2+=s1[i];
    for(int i=0;i<l;i++)if(s1[i]!=s2[i])cnt++;
    cout<<cnt;
    return 0;
}
