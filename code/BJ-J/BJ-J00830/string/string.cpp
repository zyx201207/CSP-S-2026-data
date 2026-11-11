#include<bits/stdc++.h>
using namespace std;
int n,a[114514];
long long len=0;
char c[114514];
string s;
int check(string x){
    int ans;
    for(long long i=0;i<len/2;i++){
        if(x[i]!=x[len-i-1]){
            ans++;
        }
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    cout<<check(s);
    return 0;
}
