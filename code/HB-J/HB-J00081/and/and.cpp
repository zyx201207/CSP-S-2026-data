//O(n^2)


#include <bits/stdc++.h>

using namespace std;

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int times;

int help(int x,vector<int> num,int time){
    int m=0;

    if(time==1) return x;

    for(int i=0;i<num.size();++i){
        auto p = num;
        p.erase(p.begin()+i);
        m=max(help(x&num[i],p,time-1),m);
    }

    return m;
}

int main(){
    fastio();

    auto f1 = freopen("and.in","r",stdin);
    auto f2 = freopen("and.out","w",stdout);

    int n;
    cin>>n>>times;
    vector<int> a(n-1);
    int last;               //shun xu
    for(int i=0;i<n-1;++i)cin>>a[i];
    cin>>last;

    cout<<help(last,a,times)<<" ";

    cout<<endl;
    return 0;
}