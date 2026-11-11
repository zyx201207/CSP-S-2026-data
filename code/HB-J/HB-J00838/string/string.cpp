#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int n,a,cnt;
string s1,s2,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s1+=c;
        }
    }
    s2=s1;
    reverse(s1.begin(),s1.end());
    for(int i=0;i<s1.size()/2;i++){
        if(s1[i]!=s2[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
