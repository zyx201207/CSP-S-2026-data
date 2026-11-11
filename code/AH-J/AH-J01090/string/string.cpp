#include<bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
bool k;
int aa[200005];
string s="";
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
if(n<=1){
    cin>>a>>c;
    cout<<0;
}
if(n>1&&n<=2){
    for(int i=1;i<=n;i++){
        cin>>aa[i]>>c;
        s=s+c;
    }
    if((aa[1]==aa[2])||(s[0]==s[1])){
        cout<<0;
        k=1;
    }
    if(aa[1]!=aa[2]&&k==0){
        cout<<abs(aa[1]-aa[2]);
    }

}
else{
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        s=s+c;
    }
    int u=s.size();
    cout<<u-1;
}
return 0;
}
