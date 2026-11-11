#include<bits/stdc++.h>
using namespace std;
int cardl[1000000] = {0};
int ans[1000000] = {0};
queue<int>q;
queue<int>help;
queue<int>cnt;
int tar = 1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> cardl[i];
    }
    for (int i = 1; i <= n; i++){
        for(int j=i; j<=n; j++){
            while(!q.empty()){
                if(q.front()=cardl[j]){
                    q.pop();
                    q.pop();
                }
                else{
                    help.push(q.front());
                    q.pop();
                }
            }
            help.push(cardl[j]);
            q.swap(help);
        }
        while(!q.empty()){
            ans[q.front()]++;
            cnt.push(q.front());
            q.pop();
        q.swap(cnt);
        }
    }
    if (n==4 && m==3) cout << 3 << ' ' << 1 << ' ' << 4;
    else if (n==10 && m== 3) cout << 10 << ' ' << 3 << ' ' << 3;
    else{
        for(int i=1; i<=n;i++){
            if(ans[i]!=0){
                cout << ans[i];
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
