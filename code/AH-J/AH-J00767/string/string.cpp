#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n,cnt=0,x,pos=0;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>x;
        cnt+=x;
        cin>>s1;
        for(LL i=1;i<=x;i++){
            s2+=s1;
        }
    }
    LL mid=0;
    if(cnt%2==1){
        mid=(cnt+1)/2;
        for(LL i=0;i<mid-1;i++){
                if(s2[i]!=s2[cnt-1-i]){
                    pos++;
                }
        }
        cout<<pos;
        return 0;
    }
    if(cnt%2==0){
        mid=cnt/2;
        for(LL i=0;i<=mid-1;i++){
            if(s2[i]!=s2[cnt-i-1]){
                pos++;
            }
        }
        cout<<pos;
    }
    return 0;
}
