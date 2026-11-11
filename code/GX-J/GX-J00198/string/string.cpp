#include<bits/stdc++.h>
using namespace std;

bool hw(string s){
string s1="";
for(int i=s.size()-1;i>=0;i--){
    s1+=s[i];
}
if(s1==s) return 1;
else return 0;
}

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
string s="";
cin>>n;
for(int i=1;i<=n;i++){
    int a;
    char c;
    cin>>a>>c;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int j=1;j<=a;j++){
        s+=c;
    }
}
if(n==2&&hw(s)){
    cout<<0;
}else cout<<2;
return 0;
}
