#include<bits/stdc++.h>
using namespace std;
string to2(int x){
    string s;
    while(x!=0){
        s+=char(x%2+'0');
        x/=2;
    }
    return s;
}
struct s2{
    int p;
    int w,s1;
}k[200005];
bool cmp(s2 x,s2 y){
    if(x.w==y.w){
        return x.s1>y.s1;
    }
    return x.w>y.w;
}
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        string c=to2(a[i]);
        k[i].w=c.size();
        k[i].p=a[i];
        for(int j=0;j<c.size();j++){
            if(c[j]==1){
                k[i].s1++;
            }
        }
    }
    sort(k,k+n,cmp);
    int cnt=k[0].p;
    for(int i=0;i<m;i++){
        cnt=cnt&k[i].p;
    }
    cout<<cnt;
    return 0;
}
