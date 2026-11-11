#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char ch[250000];
ll nb[250000];
ll sum=0;
ll j=0;
ll n;
ll ans=0;

struct tg{
    bool layer;
    ll o;
    char c;
};

bool cmp(tg x,tg y){
    if(x.o==y.o){
        return (x.layer=0)?1:0;
    }
    return (x.o<y.o)?1:0;
}

tg tag[250000];

/*void printrrr(){
    for(int i=0;i<j;i++){
        cout << tag[i].o << " " << tag[i].c << " ("<<tag[i].layer << ")\n";
    }
}*/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>nb[i]>>ch[i];
        sum+=nb[i];
    }
    ll t=0;
    for(ll i=0;t<(sum/2)+1;i++){
        tag[j].o=t;
        tag[j].c=ch[i];
        tag[j].layer=0;
        t+=nb[i];
        j++;
    }
    t=0;
    for(ll i=n-1;t<(sum/2)+1;i--){
        tag[j].o=t;
        tag[j].c=ch[i];
        tag[j].layer=1;
        t+=nb[i];
        j++;
    }
    sort(tag,tag+j,cmp);
    //printrrr();
    tg ltt0;//latest ground tag
    tg ltt1;//latest roof tag
    tg crt;
    for(int i=0;i<j;i++){
        crt=tag[i];
        if(ltt0.c != ltt1.c && crt.o!=0){
            ans+=crt.o-max(ltt1.o,ltt0.o);
            //cout << crt.o <<" " << ans << "\n";
        }
        if(crt.layer==0){
            ltt0=crt;
        }
        if(crt.layer==1){
            ltt1=crt;
        }
    }
    if(ltt0.c != ltt1.c && crt.o!=0){
        ans+=crt.o-max(ltt1.o,ltt0.o);
        //cout << crt.o <<" " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}
