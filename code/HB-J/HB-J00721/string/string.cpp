#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
long long cnt=0,sum=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long s1=s.size();
    for(int i=0;i<s1/2;i++){
        if(s[i]!=s[s1-i-1]) sum++;
    }
    cout<<sum;
    return 0;
}
