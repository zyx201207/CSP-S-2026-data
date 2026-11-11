#include<bits/stdc++.h>
using namespace std;
string s,c;
long long a[10000005],n,cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }

    for(long long i=0;i<n;i++){
        for(long long j=i;j-i<a[i];j++){
            s[i]=c[j];
        }
    }
    long long len=s.size(),vv;
    if(len/2==0)vv=len/2;
    else vv=len/2+1;

    for(long long i=0;i<vv;i++){
        if(s[i]-'a'!=s[len-i]-'a')cnt++;
    }
    cout<<cnt;
    return 0;
}
