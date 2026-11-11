#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        string sb;
        cin>>sb;
        for(int j=1;j<=m;j++){
            s=s+sb;
        }
    }
    int cnt=0;
    for(int i=0;i<=s.size()/2-1;i++){
        if(s[s.size()-1-i]!=s[i]){
            cnt++;

        }
    }
    cout<<cnt;
}