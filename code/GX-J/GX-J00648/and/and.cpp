#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500;

struct STU{
    int a;
    int Is1;
}node[N];

int n , m;
int ans;

bool cmp(STU a1 , STU a2){
    if(a1.Is1 == a2.Is1) return a1.a > a2.a;
    else return a1.Is1 > a2.Is1;
}

void TtoT(int a, int k){
    int lin = 0;
    while(1){
        if(pow(2 , lin) > a) break;
        else lin++;
    }
    lin--;
    for(int i = lin ; i >= 0 ; i--){
        if(a - pow(2 , i) >= 0){
            node[k].Is1++;
            a -= pow(2 , i);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> node[i].a;
        TtoT(node[i].a , i);
    }
    sort(node + 1 , node + n + 1 , cmp);
    ans = node[1].a;
    for(int i = 2; i <= m; i++){
        ans = (ans & node[i].a);
    }
    cout << ans;
    return 0;
}