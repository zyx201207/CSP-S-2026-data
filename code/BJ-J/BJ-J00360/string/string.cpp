#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],len;
char c[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s.push_back(c[i]);
        }
    }
    len=s.size();
    long long ans=0;
    for(int i=0,j=len-1;i<len/2,j>len/2-1;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
