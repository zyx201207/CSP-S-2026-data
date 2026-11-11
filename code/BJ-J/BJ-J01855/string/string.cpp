#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000001];
char c[1000000001];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long len=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long cnt=len/2;
    for(int i=len/2+len%2+1;i<=len;i++){
        for(int j=1;j<=len/2;j++){
            if(s[i]==s[j]){
                cnt--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
