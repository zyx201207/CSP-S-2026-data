#include<bits/stdc++.h>
using namespace std;
int n;
long long len=0,cnt=0;
struct si
{
    long long ai;
    char ci;
}S[200010];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i=0;i<n;i++){
        cin >> S[i].ai >> S[i].ci;
        len+=S[i].ai;
    }
    for(long long i=0;i<n;i++)s+=S[i].ai*S[i].ci;
    for(long long i=0;i*2<=len;i++){
        if(s[i]!=s[len-1-i])cnt++;
    }
    cout << cnt;
    return 0;
}
