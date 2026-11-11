#include <bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int main(){
//freopen("string","r",stdin);
//freopen("string.out","w",stdout);
int n;
cin>>n;
int ans=0,y=1;
long long a[N];
char c[N];
char s[N];
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
    for(int j=y;j<=y+a[i];j++){
        s[j]==c[i];
        y++;
    }
    }
    if(n<=1){
        cout<<0;
    }
    long long l=1000000000000000000;
    int wfl=2;
    for(int i;i<=l;i++){
        if(s[i]==s[l+1-i]){
           if(i==l) {
            wfl==0;
           }else{continue;}

        }else{break;}
    }if(wfl==0){
    cout<<0;}
return 0;
}
