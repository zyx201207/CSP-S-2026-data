#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n , m;
    cin >> n>> m;
    int a[100001],cnt[10000001]={0};
    for(int i = n ; i<= n ; i++){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i++){
        int e[100001]={0};
        stack<int>q;
        for(int j = i ; j <= n ; j++){
            if(e[a[i]]==0){
                q.push(a[i]);
                e[a[i]]++;
            }else{
                for(int k = 1 ; k <= j-i-1 ; k++){
                    int w=q.front();
                    e[w]--;
                    q.pop();
                }
            }
        }
    }
    for(int i = 1 ; i <= m ; i++){
    cout << a[i]<<" ";
    }
    return 0;
}
