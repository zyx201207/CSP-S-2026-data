#include<bits/stdc++.h>
using namespace std;
int c[500001];
int ans[300001];
vector<int> d;
int fd(int k){
    for(int i = 0;i < d.size();i++){
        if(d[i] == k) return i;
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    int t;
    for(int i = 1;i <= n;i++){
        d.clear();
        for(int j = i;j <= n;j++){
            t = fd(c[j]);
            if(t != -1){
                while(d.size() >= t+1){
                    d.pop_back();
                }
            }
            d.push_back(c[j]);
            /*for(int i = 0;i < d.size();i++){
                cout << d[i] << ' ';
            }*/
        }
        for(int j = 1;j <= m;j++){
            if(fd(j) != -1){
                ans[j]++;
                //cout << j << '\n';
            }
        }
        //cout << endl;
    }
    //cout << endl;
    for(int j = 1;j < m;j++){
        cout << ans[j] << ' ';
    }
    cout << ans[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
