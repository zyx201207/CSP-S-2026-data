#include <bits/stdc++.h>
using namespace std;
struct e{
    long long x;
    char b;
}s[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a=0,sum=0,su=0,lt=0;
    cin>>a;
    if(a==1){
        cout<<0;
        return 0;
    }
    long long rt=a-1;
    for(long long i=0;i<a;i++){
        cin>>s[i].x>>s[i].b;
        sum+=s[i].x;
    }
    if(a==2){
        cout<<min(s[0].x,s[1].x);
        return 0;
    }
    while(lt!=rt){
        if(s[lt].b!=s[rt].b){
            su+=min(s[lt].x,s[rt].x);
            if(s[lt].x>=s[rt].x){
                s[lt].x-=s[rt].x;
                rt--;
            }else{
                s[rt].x-=s[lt].x;
                lt++;
            }
        }else{
            if(s[lt].x>=s[rt].x){
                s[lt].x-=s[rt].x;
                rt--;
            }else{
                s[rt].x-=s[lt].x;
                rt++;
            }
        }
    }
    cout<<su;
    return 0;
}
