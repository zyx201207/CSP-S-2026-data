#include<bits/stdc++.h>
using namespace std;
int n,x,diff;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        for(int j=1;j<=x;j++)s+=a;
    }
    if(s.size()%2==1){
        for(int i=0;i<(s.size()-1)/2;i++)if(s[i]!=s.size()-i-1)diff++;
    }else{
        for(int i=0;i<s.size()/2;i++)if(s[i]!=s.size()-i-1)diff++;
    }
    cout<<diff;
}
