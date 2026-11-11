#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int L;
    cin>>L;
    int cnt=0;
    for(int i=1;i<=L;i++){
        int n=0;
        cin>>n;
        char c;
        cin>>c;
        for(int j=0;j<n;j++){
            s[cnt]=c;
            cnt++;
        }
    }
    int m=0;
    int x=s.size()-1;
    for(int i=0;i<cnt/2;i++){
        if(s[i]!=s[x-i]){
            m++;
        }
    }
    cout<<m;
    return 0;
}
