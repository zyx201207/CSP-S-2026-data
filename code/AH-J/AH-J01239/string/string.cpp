#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=0;i<n;i++){
        int shu;
        char ch;
        cin>>shu>>ch;
        while(shu--){
            s=s+ch;
        }
    }
    long long cnt=0;
    for(int z=0,y=s.size()-1;z<y;z++,y--){
        if(s[z]!=s[y]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
