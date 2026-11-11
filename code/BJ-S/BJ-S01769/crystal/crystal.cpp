#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int same=0,cr_max=0;
int n, m;
int num[100001];
int crystal[500000];

void dfs(int sycs) {
    if(sycs==0) return;
    for(int i=0;i<n;++i){
        if(crystal[i]<cr_max){
            ++crystal[i];
            --num[crystal[i]-1];++num[crystal[i]];
            for(int j=0;j<cr_max;++j){
                same=max(same,num[j]);
            }
            dfs(sycs-1);
            --crystal[i];
            --num[crystal[i]+1];++num[crystal[i]];
        }
    }
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    memset(num,0,sizeof(num));
    for(int i=0;i<n;++i){
        cin >> crystal[i];
        ++num[crystal[i]];
        if(crystal[i]>cr_max) cr_max = crystal[i];
    }
    dfs(m);
    cout << same;

    return 0;
}