#include<bits/stdc++.h>
using namespace std;
struct part{
    long long a;
    char s;
}p[200005];
int n,t=0;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].s;
    }
    while(l<r){
        if(p[l].a>p[r].a){
            if(p[l].s!=p[r].s){
                ans+=p[r].a;
             //   cout<<t++<<' '<<p[l].s<<' '<<p[r].s;
            }
            //cout<<ans;
            p[l].a-=p[r].a;
         //   cout<<' '<<p[l].a<<endl;
            r--;
        }
        else if(p[l].a<p[r].a){
            if(p[l].s!=p[r].s){
                ans+=p[l].a;
               // cout<<t++<<' '<<p[l].s<<' '<<p[r].s;
            }
            p[r].a-=p[l].a;
          //  cout<<' '<<p[r].a<<endl;
            l++;
        }
        else if(p[l].a==p[r].a){
            if(p[l].s!=p[r].s){
                ans+=p[l].a;
                //cout<<t++<<' '<<p[l].s<<' '<<p[r].s<<endl;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
