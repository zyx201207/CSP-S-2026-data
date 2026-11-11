#include<bits/stdc++.h>
using namespace std;
char c;
int a;
int n;
string s;
int main(){
    ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long cnt=0;
    long long len=s.size();
    for(long long i=0;i<=(len-1)/2;i++){
        if(s[i]!=s[len-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
