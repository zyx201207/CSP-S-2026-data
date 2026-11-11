#include<bits/stdc++.h>
using namespace std;
long long n,ans,l=1,r;
struct st{
    long long a,now;
    char c;
}s[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        s[i].now=s[i].a;
    }while(l<r){
        if(s[l].c==s[r].c){
            if(s[l].now<s[r].now){
                s[r].now-=s[l].now;
                s[l].now=0;
            }else if(s[l].now>s[r].now){
                s[l].now-=s[r].now;
                s[r].now=0;
            }else if(s[l].now==s[r].now){
                s[l].now=0;
                s[r].now=0;
            }
        }else if(s[l].c!=s[r].c){
            if(s[l].now<s[r].now){
                ans+=s[l].now;
                s[r].now-=s[l].now;
                s[l].now=0;
            }else if(s[l].now>s[r].now){
                ans+=s[r].now;
                s[l].now-=s[r].now;
                s[r].now=0;
            }else if(s[l].now==s[r].now){
                ans+=s[l].now;
                s[l].now=0;
                s[r].now=0;
            }
        }if(s[l].now==0){
            l++;
        }if(s[r].now==0){
            r--;
        }
    }cout<<ans;
    return 0;
}
