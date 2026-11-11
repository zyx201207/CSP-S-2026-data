#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct D{
    long long a; // end point
    char c;
};
vector<D> d;
int n;
int datpl,datpr;// data point
long long middlep,l,r;// string point
long long ans=0;
int dsize=1;

int fi(long long i,int start){//find: point=>data point; i=need; st=start
    if(i>d[dsize-2].a)return dsize-1;
    else if(i<=d[start].a)return start;
    for(int j=start+1;j<dsize;j++){
        if(i<=d[j].a&&i>d[j-1].a)return j;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){cout<<0;return 0;}
    for(int i=0;i<n;i++){
        D tmp;
        cin>>tmp.a>>tmp.c;
        if(i==0)d.push_back(tmp);
        else{
            tmp.a+=d[dsize-1].a;
            if(tmp.c==d[dsize-1].c)d[dsize-1].a=tmp.a;
            else {d.push_back(tmp);dsize++;}
        }
    }
    if(dsize==2){
        if(d[0].c==d[1].c){cout<<0;return 0;}
        cout<<min(d[0].a,d[1].a-d[0].a);
        return 0;
    }
    middlep=d[dsize-1].a/2-1;
    if(n%2==1){l=middlep;r=middlep+2;}
    else l=middlep,r=middlep+1;
    datpl=fi(l,0);
    datpr=fi(r,datpl);
    for(;r<d[dsize-1].a&&l>0;){
        long long dl,dr; //dao liang duan de jv li
        if(datpl==0)dl=l;else dl=l-d[datpl-1].a+1;
        if(datpr==dsize-1)dr=d[dsize-1].a-r+1;else dr=d[datpr].a-r+1;
        if(dl<=dr){
            if(d[datpl].c!=d[datpr].c)ans+=dl;
            l-=dl;r+=dl;
        }
        if(dl>dr){
            if(d[datpl].c!=d[datpr].c)ans+=dr;
            l-=dr;r+=dr;
        }
        if(datpl>0)datpl=fi(l,datpl-1);
        if(datpr<dsize-1)datpr=fi(r,datpr);
    }
    if(d[dsize-1].c!=d[0].c&&(d[0].a==1||(d[dsize-1].a-d[dsize-2].a)==1))ans++;
    cout<<ans;
    return 0;
}

// standard method: erfen qiege
// the difficulty: data
