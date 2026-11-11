#include<bits/stdc++.h>
using namespace std;

long long n,x;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        for(int i=1;i<=x;i++) s.push_back(c);
    }
    long long sum=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) sum++;
    }
    cout<<sum;
    return 0;
}


