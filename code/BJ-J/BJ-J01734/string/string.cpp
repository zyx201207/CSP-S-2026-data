#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct px{
    ll a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<px> p(n+5);
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>p[i].a>>p[i].c;
    }
    int i=0,r=n-1;
    ll countt=0;
    while(i<r){
        if(p[i].c!=p[r].c){
            if(p[i].a>p[r].a){
                countt+=p[r].a;
                p[i].a-=p[r].a;
                r--;
            }else if(p[i].a<p[r].a){
                countt+=p[i].a;
                p[r].a-=p[i].a;
                i++;
            }else{
                countt+=p[i].a;
                r--;
                i++;
            }
        }else{
            if(p[i].a>p[r].a){
                p[i].a-=p[r].a;
                r--;
            }else if(p[i].a<p[r].a){
                p[r].a-=p[i].a;
                i++;
            }else{
                r--;
                i++;
            }
        }
    }
    cout<<countt;
    return 0;
}
