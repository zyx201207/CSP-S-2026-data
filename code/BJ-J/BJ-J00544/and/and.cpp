#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005];
bool b[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i < n;i++) cin>>a[i];
    for(int j = 30;j >= 0;j--){
        int cnt = 0,k = INT_MAX;
        for(int i = 0;i < n;i++){
            int cur = (a[i] & 1<<j)>>j;
            if(cur == 1 && b[i] == 0){
                cnt++;
                if(cnt <= m) k &= a[i];
                //cout<<i<<endl;
            }
        }
        if(cnt == m){
            cout<<k;
            return 0;
        }
        if(cnt > m){
            cnt = 0,k = INT_MAX;
            for(int i = 0;i < n;i++){
                if((a[i] & 1<<j)>>j == 0){
                    b[i] = 1;

                }
            }
        }
    }
    int cnt = 0,k = INT_MAX;
    for(int i = 0;i < n;i++){
        if(b[i] == 0){
            cnt++;
            k &= a[i];
        }
        if(cnt == m){
            cout<<k;
            return 0;
        }
    }
    return 0;

}