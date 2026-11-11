#include<bits/stdc++.h>
using namespace std;
int a[500005], top = 0;
void push(int x){
    top++;
    a[top] = x;
    return;
}
void pop(){
    top--;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m, card[500005], num[300005] = {};
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> card[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            bool f = true;
            for(int k = 1;k <= top;k++){
                if(a[k] == card[j]){
                    f = false;
                    break;
                }
            }
            if(f) push(card[j]);
            else{
                while(a[top] != card[j]) pop();
            }
        }
        for(int j = 1;j <= top;j++){
            num[a[j]]++;
        }
        while(top) pop();
    }
    for(int i = 1;i <= m;i++) cout << num[i] << ' ';
    return 0;
}
