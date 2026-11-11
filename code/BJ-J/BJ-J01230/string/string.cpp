#include<bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
struct str{
    int cnt;
    char c;
}a[maxn];
int n,nowl,nowr,l;
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].c;
        nowr+=a[i].cnt;
    }
    l=n;nowl=1;
    for(int i=1;i<=n;i++){
        int len=a[i].cnt;
        nowl+=len;
        //cout<<len<<"\n";
        while(len>0){
            //cout<<"*\n";
            if(a[l].c!=a[i].c){
                //cout<<"%\n";
                if(a[l].cnt<=len){
                    len-=a[l].cnt;
                    nowr-=a[l].cnt;
                    ans+=a[l].cnt;
                    a[l].cnt=0;
                    l--;
                }
                else{
                    a[l].cnt-=len;
                    nowr-=len;
                    ans+=len;
                    len=0;
                }
            }
            else{
                if(a[l].cnt>len){
                    nowr-=len;
                    a[l].cnt-=len;
                    len=0;
                }
                else{
                    nowr-=a[l].cnt;
                    len-=a[l].cnt;
                    a[l].cnt=0;
                    l--;
                }
            }
        }
        //cout<<nowl<<" "<<nowr<<"\n";
        if(nowl>=nowr){
            break;
        }
    }
    cout<<ans;
    return 0;
}
