#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200001];
char c[200001];
string s;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        for(long long j=1;j<=a[i];j++)s+=c[i];
    }
    s='0'+s;
    long long cnt=0,len=s.size();
    for(long long i=1;i<=len/2;i++){
        if(s[i]!=s[len-i]){
            cnt++;
            s[i]=s[len-i];
        }
    }
    cout << cnt;

    return 0;
}
