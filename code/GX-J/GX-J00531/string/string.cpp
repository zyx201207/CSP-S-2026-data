#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
vector<char> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long a;
    char c;
    for(long long i=0;i<n;i++){
        cin>>a>>c;
        for(long long j=0;j<a;j++) s.push_back(c);
    }
    for(long long i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]) cnt++;
    }
    cout<<cnt;
    return 0;
}
