#include<bits/stdc++.h>
using namespace std;
int a,n,ans;
string s;
short c;
int main(){
    freopen("string.in","r",std.in);
    freopen("string.in","w",std.out);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a>>c;
    for(int j=0;j<a;j++)
        s+=c;
}
int y=sizeof(s);
for(int i=0;;i++){
    for(int j=y;;j++){
        if(i>j) break;
        if(s[i]!=s[j])
            ans++;
    }
}
cout<<ans;
return 0;
}
