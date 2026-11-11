#include <iostream>
using namespace std;
typedef long long ll;
int n;ll nowpos=1;
string si;
struct node{
    ll startpos;int chipos;char c;
    int endpos(){return startpos+chipos-1;}
} s[200010];
char charof(ll pos){
    ll ljie=1,rjie=n;
    while(1){
        if(s[ljie].startpos<=pos and s[ljie].endpos()>=pos) return s[ljie].c;
        if(s[rjie].startpos<=pos and s[rjie].endpos()>=pos) return s[rjie].c;
        if(s[(ljie+rjie)/2].startpos<=pos and s[(ljie+rjie)/2].endpos()>=pos) return s[(ljie+rjie)/2].c;
        if(pos<s[(ljie+rjie)/2].startpos){
            rjie=(ljie+rjie)/2;
        }
        if(s[(ljie+rjie)/2].endpos()<pos){
            ljie=(ljie+rjie)/2;
        }
        //cerr<<"ljie"<<ljie<<" rjie"<<rjie<<'\n';
    }
}

int main(){

    #if 01
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    #endif // freopen
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;char c;cin>>a>>c;
        s[i]={nowpos,a,c};
        nowpos+=a;
        //for(int j=0;j<a;++j) s[i+j]=c;
    }nowpos--;

    ll ans=0;
    for(ll le=(nowpos%2==1?(nowpos+1)/2:nowpos/2),ri=(nowpos%2==1?(nowpos+1)/2:nowpos/2+1);le>=1;le--,ri++){
        if(charof(le)!=charof(ri)) ++ans;
        //if(s[le]!=s[ri]) ++ans;
    }cout<<ans;

    //O s.size() log n
    //O s.size() +s.size()
}
