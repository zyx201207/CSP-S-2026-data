#include <bits/stdc++.h>
using namespace std;


int n,m,self,a[300010];
int vis[300010];
stack <int> b;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out", 'w',stdout);
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for (int i = 1;i<=m;i++){
        self = i-1;

        while(self==n){
            if (vis[self] == 1){
                b.push(a[self]);
                self++;
                vis[self] = 0;
            }
            else {
                while(b.top()==a[self]){
                    b.pop();
                }
                self++;
            }
        }
        cout << b.top();
    }

}
