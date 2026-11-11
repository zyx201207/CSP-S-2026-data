#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct number{
    int s;
    int x[40];
    bool fl = true;
}a[N];
int g[40];
int n,m;
long long ans;
void fx(int y){
    int t = a[y].s,j = 0,l = 0;
    while(t){
        if(t % 2 == 1){
            g[j]++;
            a[y].x[j] = 1;
        }
        j++;
        t /= 2;
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int maxm = 0;
    for(int i=0;i<n;i++){
        cin >> a[i].s;
        fx(i);
    }
    for(int i=31;i>=0;i--){
        if(g[i] >= m){
            for(int j=0;j<n;j++){
                if(a[j].x[i] == 0 && a[j].fl){
                    a[j].fl = 0;
                    for(int k=0;k<=31;k++)
                        g[k] -= a[j].x[k];
                }
            }
            ans += pow(2,i);
        }
    }
    cout << ans;
    return 0;
}
