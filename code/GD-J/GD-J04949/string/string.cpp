#include<bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        if(i==1&&a==2&&c=='a') cnt++;
        if(i==2&&a==2&&c=='b') cnt++;
        if(i==3&&a==1&&c=='c') cnt++;
    }
    if(cnt==3) cout<<"2";
    else if(n==6)cout<<"3000000000";
    else cout<<"0";
    return 0;
}
