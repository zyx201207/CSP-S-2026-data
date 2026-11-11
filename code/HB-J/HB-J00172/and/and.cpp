#include <bits/stdc++.h>
using namespace std;


struct Num{
    int num1;
    int cnt1;
};
Num num[200002];

bool cmp(Num a, Num b){
    return a.cnt1 > b.cnt1;
}
long long aaa = 0;
void f(int s,int a){
    if(a == 0) {
        num[s].cnt1 = 0;
        num[s].num1 = 0;
    } else{
        int b[20000] = {0};
        long long c = 1;
        int i = 0;
        int cnt = 1;
        while(a != 1){
            int d = a % 2;
            b[i] = d;
            if(d == 1) cnt++;
            a /= 2;
            i++;
        }
        for(int j = i - 1; j >= 0; j--){
            c = c * 10 + b[j];
        }
        num[s].cnt1 = cnt;
        num[s].num1 = c;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int aaa = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        f(i,a);
        aaa = max(aaa,a);
    }
    sort(num,num + n,cmp);
    while(aaa != 1){
        aaa / 2;
    }
    long long ans = 1;
    for(int i = 0; i < m; i++){
        ans = ans & num[i].num1;
    }
    return 0;
}
