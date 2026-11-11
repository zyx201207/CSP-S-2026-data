#include<bits/stdc++.h>
using namespace std;
long long n,a,num=0;
char b;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a >> b;
        for(long long j=0;j<a;j++) s+=b;
    }
    long long l=s.size();
    for(long long int i=0;i<l/2;i++) if(s[i]!=s[l-i-1]) num++;
    cout<<num;
    return 0;
}
