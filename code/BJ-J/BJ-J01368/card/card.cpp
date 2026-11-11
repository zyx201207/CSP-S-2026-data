#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N],b[M];

int main(){
    freopen("card.in",stdin,"r");
    freopen("card.out",stdout,"w");

    int n,m;
    cin >> n >> m;
    for(int i = 1;; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        vector<int> c;
        for(int j = i + 1; j <= n; j++){
            c.push_back(a[j]);
            for(int k = 0; k < c.size(); k++){
                if(c[k] == a[j]){
                    for(int x = 1; x < k; x++){
                        c[x] = 0;
                    }
                    break;
                }
            }
        }
        int cnt = 0;
        for(int j = 0; j < c.size(); j++){
            if(c[i] != 0) cnt++;
        }
        b[cnt] = i;
        bool b = 0;
        for(int j = 1; j <= m; j++){
            if(b[j] == 0) b = 1;
        }
        if(!b) break;
    }
    for(int i = 1; i <= m; i++){
        cout << b[i] << endl;
    }
    return 0;
}
