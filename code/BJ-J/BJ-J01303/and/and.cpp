#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N=2e5+5;

int n,m;
LL a[N];
vector<int> vec[66];
int base=64,tot;
bitset<66> ans;

inline void f(int idx){
    for(int i=1,x=a[idx];i<base&&x;i++,x>>=1){
        if(x&1){vec[i].push_back(idx);}
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //freopen("and5.in","r",stdin);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++){cin>>a[i];f(i);}

    //for(int i=1;i<=64;i++){sort(vec[i].begin(),vec[i].end());}

    for(int i=64;i>=1;i--){
        if(vec[i].size()>=m){
            ans[i]=true;
            base=i; tot=vec[i].size();
            for(int j=1;j<base;j++){vec[j].clear();}
            for(int j:vec[base]){f(j);}
        }
    }

    LL res=0;
    for(int i=64;i>=1;i--){
        res<<=1;
        res+=ans[i];
    }

    cout << res << endl;

    return 0;
}
