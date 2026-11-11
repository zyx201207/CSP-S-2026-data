#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,a;i<=n;i++){
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++) s+=c;
    }
    for(int i=0;i<(s.size()-1)/2+1;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
