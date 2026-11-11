#include <bits/stdc++.h>
using namespace std;
unsigned long long cnt=0;
struct str{
    long long num;
    char a;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin>>n;
    str s[n];
    if(n==1){
        cout<<0;
    }else{
        for(long i=0;i<n;i++){
            cin>>s[i].num>>s[i].a;
        }
        for(long long i=0;i<=n/2;i++){
            if(s[i].a!=s[n-1-i].a){
                cnt+=min(s[i].num,s[n-1-i].num);
                if(s[i].num>=s[n-1-i].num){
                    s[i].num-=s[n-1-i].num;
                }else{
                    s[n-1-i].num-=s[i].num;
                }
            }else{
                if(s[i].num>=s[n-1-i].num){
                    s[i].num-=s[n-1-i].num;
                }else{
                    s[n-1-i].num-=s[i].num;
                }
            }
            if(s[i].a!=s[n-2-i].a&&i<n-1){
                cnt+=min(s[i].num,s[n-2-i].num);
                if(s[i].num>=s[n-2-i].num){
                    s[i].num-=s[n-2-i].num;
                }else{
                    s[n-2-i].num-=s[i].num;
                }
            }else{
                if(s[i].num>=s[n-2-i].num){
                    s[i].num-=s[n-2-i].num;
                }else{
                    s[n-2-i].num-=s[i].num;
                }
            }
        }
        cout<<cnt;
    }
}
