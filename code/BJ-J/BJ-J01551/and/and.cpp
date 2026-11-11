#include<bits/stdc++.h>
using namespace std;
struct nd{
    string s;
    long long nbr,fn;
}a[200005];
bool cmp(nd a,nd b){
    return a.s>b.s;
}
long long n,m,maxx=-1e9;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].nbr;
        long long x=a[i].nbr;
        while(x){
            a[i].s=char(x%2+'0')+a[i].s;
            x>>=1;
        }
        string num=a[i].s;
        a[i].fn=num.size();
        maxx=max(maxx,(long long)(num.size()));
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].s.size()-maxx;j++){
            a[i].s='0'+a[i].s;
        }
        //cout<<a[i].s<<endl;
    }
    sort(a+1,a+n+1,cmp);
    //cout<<a[3].s<<" "<<a[4].s<<endl;
    int ans,id;
    //cout<<a[4].fn<<" "<<a[3].fn<<endl;
    for(int i=1;i<=n;i++){
        if(a[i].fn==a[i+1].fn){
            ans=a[i].nbr;
            id=i;
            break;
        }
    }
    //cout<<id<<endl;
    for(int i=id;i<=id+m-1;i++){
        ans&=a[i].nbr;
    }
    cout<<ans;
    return 0;
}
