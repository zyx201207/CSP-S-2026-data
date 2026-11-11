#include<bits/stdc++.h>
using namespace std;
struct s{
    int cnt;
    char a;
}ss[500005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ss[i].cnt>>ss[i].a;
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(ss[l].a==ss[r].a && ss[l].cnt==ss[r].cnt){
            l++;r--;
        }else if(ss[l].a==ss[r].a){
            if(ss[l].cnt>ss[r].cnt){
                ss[l].cnt-=ss[r].cnt;
                r--;
            }else{
                ss[r].cnt-=ss[l].cnt;
                l++;
            }
        }else if(ss[l].cnt==ss[r].cnt){
            ans+=ss[l].cnt;
            l++;r--;
        }else{
            if(ss[l].cnt>ss[r].cnt){
                ans+=ss[r].cnt;
                ss[l].cnt-=ss[r].cnt;
                r--;
            }else{
                ans+=ss[l].cnt;
                ss[r].cnt-=ss[l].cnt;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}

