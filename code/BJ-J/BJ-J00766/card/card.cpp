#include <bits/stdc++.h>
using namespace std;

int n, m;
int ls[500005], num[300005];
bool b[300005];
void cot(int s){
    for(int i = s;i <= n;i++){
        if(b[ls[i]] == 0){
            b[ls[i]] = 1;
            num[ls[i]]++;
        }else{
            return ;
        }
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = n;i >= 1;i--){
        cin >> ls[i];
    }
    for(int i = 1;i <= n;i++){
        cot(i);
        for(int i = 1;i <= m;i++){
            b[i] = 0;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << num[i] << " ";
    }
    return 0;
}
