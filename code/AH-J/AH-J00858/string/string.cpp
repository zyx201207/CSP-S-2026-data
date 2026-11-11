#include<bits/stdc++.h>
using namespace std;
int n,x;
long long ans;
char ch;
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>ch;
        for(int j=1;j<=x;j++){
            str+=ch;
        }
    }
    for(size_t i=0;i<=str.size()/2+1;i++){
        if(str[i]!=str[str.size()-i-1]){
            ans++;
            str[str.size()-i-1]=str[i];
        }
    }
    cout<<ans;
    return 0;
}
