#include<bits/stdc++.h>
#define MAXN 500006
using namespace std;

struct node{
    int ndVal,ndP,ndCNT;//node_p,node_cnt
};

long long n,m;
int a[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<node> v;//去重数组
    v.push_back({a[1],1,1});
    int tmpi=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]!=tmpi) {
            v.push_back({a[i],i,1});
            tmpi=a[i];
        }
        else v[v.size()-1].ndCNT++;
    }

    for(int i=1,cnt=v[0].ndCNT ; i<v.size() ; i++){//尝试让a[i]作为a[1..i]的值

        if( m < (v[i].ndVal-v[i-1].ndVal)*cnt ){
            cout<<cnt;
            return 0;
        }
        else{
            m-=(v[i].ndVal-v[i-1].ndVal)*cnt;
            cnt+=v[i].ndCNT;
        }
    }
    cout<<n;
    return 0;
}
