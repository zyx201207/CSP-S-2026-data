#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n,cnt=0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int a;
        char c;
        scanf("%d %c",&a,&c);
        for(int i = a;i>0;i--){
            s.push_back(c);
        }
    }
    for(int i = 0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-1-i])cnt++;
    }
    cout<<cnt;
    return 0;
}
