#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    string s1;
    s1=s;
    reverse(s1.begin(),s1.end());
    long long diff=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s1[i])diff++;
    }
    cout<<diff/2;
    return 0;
}
