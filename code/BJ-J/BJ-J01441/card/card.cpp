#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

//vector<int> sim(int m,vector<int> &v){
//    vector<int> res(m);
//    vector<int> ps(m,-1);
//    vector<int> ot(v.size());
//    int p = 0;
//    for(int i = 0;i < v.size();i++){
//        for(int j = i;j < v.size();j++){
//            if(ps[v[j]] == -1){
//                ot[p++] = v[j];
//                ps[v[j]] = p;
//            }else{
//                p = ps[v[j]];
//                ot[p] = v[j];
//                for(int k = p + 1;k < min(ot.size(),ps.size());k++){
//                    ot[k] = 0;
//                    ps[k] = -1;
//                }
//            }
//        }
//        for(int j = 0;j < m;j++){
//            if(ps[j] != -1){
//                res[j]++;
//            }
//        }
//    }
//    return res;
//}

const int INF = 0x3f3f3f3f;

vector<int> sim(int m,vector<int> &v){
    vector<int> tb(v.size(),INF);
    vector<int> res(m);
    for(int i = 0;i < v.size();i++){
        int cb = 0;
        for(int j = i;j < v.size();j++){
            int pos = -1;
            bool flag = false;
            for(int k = 0;k <= j;k++){
                if(tb[k] == v[j]){
                    pos = k;
                    flag = true;
                }
                if(flag){
                    tb[k] = INF;
                }
            }
            if(pos == -1){
                tb[cb++] = j;
            }else{
                tb[pos] = j;
                cb = pos;
            }
        }
        for(int j = 0;j < cb;j++){
            if(tb[j] != INF){
                res[tb[j]]++;
            }
        }
    }
    return res;
}


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        scanf("%d",&v[i]);
    }
    vector<int> res = sim(m,v);
    for(int i = 0;i < res.size();i++){
        printf("%d",res[i]);
        if(i != res.size() - 1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
