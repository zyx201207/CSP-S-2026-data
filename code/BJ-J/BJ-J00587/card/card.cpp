#include<iostream>
#include<stdio.h>
using namespace std;

int n, m;
int sum[300010];
int a[500010];
int t[300010];


struct stck{
    int l[500010];
    int sz;

    int tp(){
        return l[sz];
    }
    void psh(int x){
        l[++sz] = x;
    }
    void pp(){
        l[sz--] = 0;
    }

    void ers(int x){
        sz = x;
    }

    bool emp(){
        if(sz != 0){
            return 0;
        }
        return 1;
    }
}s;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            t[j] = 0;
        }
        for(int j = i; j <= n; j++){
            if(t[a[j]] > s.sz){
                t[a[j]] = 0;
            }

            if(t[a[j]]){
                s.ers(t[a[j]]);
            }
            else{
                s.psh(a[j]);
                t[a[j]] = s.sz;
            }
        }

        for(int j = 1; j <= s.sz; j++){
            sum[s.l[j]]++;
        }
        s.ers(0);
    }

    for(int i = 1; i <= m; i++){
        cout << sum[i] << " ";
    }
    return 0;
}
