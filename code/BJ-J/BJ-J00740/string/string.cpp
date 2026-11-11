#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        int a;
        sting b;
        cin<<a<<b;
        long long c=cnt+a;
        for(int j=cnt;j<=c;j++){
            s[i]=b;}
        cnt+=a;
    }
    if(cnt%2==0){
       int y=cnt/2;
       int x=cnt/2-1;
       for(int i=y;i<=cnt;i++){
           if(s[x]!=s[y]){
             ans++;}
           x--;
           y++;
       }
    }
    else{
        int p=(cnt-1)/2;
        int x=p-1;
        int y=p+1;
        for(int i=p;i>0;i--){
            if(s[x]!=s[y]){
                ans++;}
            }
            x--;
            y++;
    }
    cout<<ans;
}
