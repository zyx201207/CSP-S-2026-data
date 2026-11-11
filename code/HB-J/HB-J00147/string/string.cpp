#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t,len=0;
    scanf("%d",&t);
    string s;
    while(t--){
        int n;char x;
        scanf("%d %c",&n,&x);
        for(int i=len;i<len+n;i++){
            s[i]=x;
        }
        len+=n;
    }
    int cnt=0;
    for(int i=0;i<(len+1)/2;i++){
        if(s[i]!=s[len-i-1]) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
