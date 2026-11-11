#include<bits/stdc++.h>
using namespace std;
int main(){
    string s[100000];
    string c[100000];
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
long long a,js=0,jsx=0;
for(int i=0;i<n;i++){
    cin>>a>>c[i];
    js+=a;
    for(long long j=js-a;j<js;j++){
        s[j]=c[i];
    }
}
for(long long l=0;l<js/2+1;l++){
    if(s[l]!=s[js-l-1]){
    jsx++;
    }
}
cout<<jsx;
}