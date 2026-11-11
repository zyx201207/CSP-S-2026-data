#include<bits/stdc++.h>
using namespace std;
int a[500000];int cnt[300000];
stack<int> stk;
bool check[300000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >>n >>m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
            memset(check,0,sizeof(check));
        for(int j=i;j<=n;j++){
            if(check[j]==0){
                stk.push(a[j]);
                check[j]=1;
            }
            else{
                while(stk.top()!=a[j]){check[stk.top()]=0;stk.pop();}
                stk.pop();
            }
        }
        while(!stk.empty()){
            cnt[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}
