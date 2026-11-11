#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct keduori{
    int len;
    char word;
}t[N];
int n,top,l,r,cnt,a,ans,mi;
char w,c;
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        if(c==w){
            cnt+=a;
        }
        else{
            t[top].len=cnt;
            t[top].word=w;
            top++;
            cnt=a;
            w=c;
        }
    }
    t[top].len=cnt;
    t[top].word=w;
    //for(int i=0;i<=top;i++){
    //    cout<<i<<" "<<t[i].len<<" "<<t[i].word<<'\n';
    //}
    l=1;
    r=top;
    while(l<r){
        if(l==r){
            break;
        }
        mi=min(t[l].len,t[r].len);
        //cout<<l<<":"<<t[l].len<<","<<t[l].word<<";"<<r<<" "<<t[r].len<<" "<<t[r].word<<"    "<<ans<<"   ";
        if(t[l].word!=t[r].word){
            ans+=mi;
        }
        //cout<<l<<":"<<t[l].len<<","<<t[l].word<<";"<<r<<" "<<t[r].len<<" "<<t[r].word<<"    "<<ans<<"   "<<mi<<"    ";
        t[l].len-=mi;
        t[r].len-=mi;
        if(t[l].len==0){
            l++;
        }
        if(t[r].len==0){
            r--;
        }
        //cout<<l<<":"<<t[l].len<<","<<t[l].word<<";"<<r<<" "<<t[r].len<<" "<<t[r].word<<"    "<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}
