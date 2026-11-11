#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10;
const int maxm=3*1e5+10;
long long a[1000001],n,m,b[1000001];
int fd(int tar,vector<int> c){
    for(int i = 0;i < c.size();i++){
        if(c[i]==tar){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        vector<int> cur;
        for(int j = i;j <= n;j++){
            int w=fd(a[j],cur);
            if(w==-1){
                cur.push_back(a[j]);
            }else{
                for(int k = w;k <= j-1;k++){
                    cur[k]=0;
                }
                cur.push_back(a[j]);
            }
        }
        for(auto k:cur){
            if(k){
                b[k]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << b[i] << " ";
    }
}
