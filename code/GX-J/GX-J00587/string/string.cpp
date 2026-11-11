#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char ch[N];
string s;
long long a[N],n,cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>ch[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++)s+=ch[i];
    }
    long long l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]!=s[l-i-1])cnt++;
    }
    cout<<cnt;
    return 0;
}
