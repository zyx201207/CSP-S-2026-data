#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long a;
char c;
long long cut;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        m+=a;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    long long l=0,r=m-1;
    while(l<r){
        if(s[l]!=s[r]){
            cut++;
        }
        l++;
        r--;
    }
    cout<<cut;
    return 0;
}
