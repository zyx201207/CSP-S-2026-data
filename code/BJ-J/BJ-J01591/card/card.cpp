#include<bits/stdc++.h>
using namespace std;
#define fs first
#define se second
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int , int> pii;
int nxt[500010];
int sy[300010];
int a[500010];
int ans[300010];
int ls[500010];
int lst[500010];
int n, m;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        nxt[i] = i+1;
        lst[i] = i-1;
    }
    for(int t = 1; t <= n; t++){
    //cout << "-----------\n";
    //cout << t << endl;
    for(int i = 1; i <= n+10; i++){
        nxt[i] = i+1;
        lst[i] = i-1;
        ls[i]=0;
    }
    nxt[0] = 1;

    for(int i = 1; i <= m; i++) sy[i]=0;
    int tl = 1;
    for(int i = t; i <= n; i++){
        //cout << "#" << i << endl;
        ls[tl] = a[i];
        if(sy[a[i]] != 0){
            int tmp = sy[a[i]];
            for(int j = nxt[sy[a[i]]]; ls[j] != a[i] && j != tl; j=nxt[j]){
                sy[ls[j]] = 0;
                //ans[ls[j]] -= i;
                tmp = j;
                //cout << "dl:" << j<< " " << ls[j] << endl;
            }
            nxt[lst[sy[a[i]]]] = nxt[tmp];
            lst[nxt[tmp]] = lst[sy[a[i]]];
        }else{
            //ans[a[i]] += i;
        }
        sy[a[i]] = tl;
        tl++;
    }
    ls[0]=0;
    for(int i = 0; i != tl; i = nxt[i]){
        ans[ls[i]]++;
    }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}