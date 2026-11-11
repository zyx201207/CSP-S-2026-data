#include <bits/stdc++.h>
using namespace std;
queue <int> a;
queue <int> b;
int ans[1010101];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        int x;
        cin>>x;
        b.push(x);
    }
    a.push(1);
    for(int i = 1;i <= m;i++){
        int c = 0;
        for(int i = 1;i <= n;i++){
            if(b.front() == a.front()){
                c = 1;
            }
            if(c){
                a.push(b.front());
                b.pop();
            }
        }
        b.push(a.front());
        a.pop();
        for(int k = 1;k <= m;k++){
            for(int j = 1;j <= n;j++){
                if(b.front() == k){
                    ans[k]++;
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
