#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b;
ll n,sum=0,ans=0,q[1000005];
char p[1000005];
bool ok=false;
struct pd{
    ll n;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>q[i]>>p[i];
        ans+=q[i];
    }
    stack<pd>R;
    queue<pd>L;
    ll tail=0;
    if(ans%2==1)ok=true;
    for(ll i=1;i<=n;i++){
        if(tail+q[i]>=ans/2+1&&ok==true){
            ans--;
            ok=false;
            q[i]--;
        }
        if(tail+q[i]>ans/2){
            if(tail<ans/2){
                R.push({q[i]-(ans/2-tail),p[i]});
                L.push({ans/2-tail,p[i]});
                tail+=q[i];
            }
            else {
                R.push({q[i],p[i]});
                tail+=q[i];
            }
        }
        else {
            L.push({q[i],p[i]});
            tail+=q[i];
        }
        //tail+=q[i];
    }
    ll c1=0,c2=0;
    char s1,s2;
    while(1){
        if(c1==0&&!L.empty()){
            c1=L.front().n,s1=L.front().c;
            L.pop();
        }
        if(c2==0&&!R.empty()){
            c2=R.top().n,s2=R.top().c;
            R.pop();
        }
        if(c1==c2){
            if(s1!=s2){
                sum+=c2;
            }
            c1=c2=0;
        }
        else {
            if(c1>c2){
                c1-=c2;
                if(s1!=s2){
                    sum+=c2;
                }
                c2=0;
            }
            if(c2>c1){
                c2-=c1;
                if(s1!=s2){
                    sum+=c1;
                }
                c1=0;
            }
        }
        if(L.empty()&&R.empty())break;
    }
    cout<<sum;
    return 0;
}
