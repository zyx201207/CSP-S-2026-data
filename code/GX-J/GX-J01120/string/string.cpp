#include<bits/stdc++.h>
using namespace std;
int n;string s;int cnt=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
//
cin>>n;
while(n--){
    long long a;
    cin>>a;
    char x;
    cin>>x;
    for(int i=0;i<a;i++){
        s+=x;
    }
}
string s1;
for(long long i=s.size()-1;i>=0;i--){
    s1+=s[i];
}
if(s1==s){
    cout<<0;
    return 0;
}

for(long long i=0;i<s.size();i++){
    if(s[i]!=s1[i])cnt++;
}
cout<<cnt/2;
return 0;
}
