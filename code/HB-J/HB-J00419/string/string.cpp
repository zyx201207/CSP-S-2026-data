#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct z{
    long long t,w,s;
    char a;
}b[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].s>>b[i].a;
    }
    int x=1,y=n;
    while(x<y){
        if(b[x].s==0){
            x++;
        }
        if(b[y].s==0){
            y--;
        }
        if(b[x].s>b[y].s){
            if(b[x].a!=b[y].a){
                ans+=b[y].s;
            }
            b[x].s=b[x].s-b[y].s;
            b[y].s=0;
            continue;
        }
        if(b[x].s<b[y].s){
            if(b[x].a!=b[y].a){
                ans+=b[x].s;
            }
            b[y].s=b[y].s-b[x].s;
            b[x].s=0;
            continue;
        }
        if(b[x].s==b[y].s){
            if(b[x].a!=b[y].a){
                ans+=b[y].s;
            }
            b[x].s=0;
            b[y].s=0;
            continue;
        }
    }
    cout<<ans;

    return 0;
}
