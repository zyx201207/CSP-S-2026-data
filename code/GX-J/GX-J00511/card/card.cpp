#include <iostream>
#include<stack>
#include<queue>
#include<string>
#include <cstdio>
using namespace std;
void game(long long i,int <stack> j,int <queue> k){
    for (long long x = 1;x <= i-1;i++){
        j.pop();
    }
    while(!j.empty()){
        k.push(j.top());
        j.pop;
    }
    while(!k.empty()){
        cnt[k.front()]++;
        k.pop();
    }

}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int <stack> c;
    int <queue> d;
    long long n,m;
    cin >> n >> m;
    long long a[n];
    int cnt[m];
    for (long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (long long i = n;i >= 1;i--){
        c.push(a[i]);
    }
    for(long long i = 1;i <= n;i++){
        game(i,c,d);
    }
    for(long long i = 0;i < m;i++){
        cout << cnt[i];
    }
    return 0;
}
