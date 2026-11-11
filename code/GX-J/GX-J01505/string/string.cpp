#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a,cnt;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    for(int i=0,j=n;i<j;i++,j--){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return 0;
}


