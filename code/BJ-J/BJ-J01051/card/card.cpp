#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+7;
int n,m,a[N],x[N],ans[N];
vector<int> res[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    x[a[n]] = n,res[n].push_back(a[n]);
    for(int i = n-1;i>=1;i--){
        if(x[a[i]]==0){
            res[i] = res[i+1];
            res[i].push_back(a[i]);
        }
        else res[i] = res[x[a[i]]];
        x[a[i]] = i;
    }
    for(int i = 1;i<=n;i++){
        while(!res[i].empty()){
            int p = res[i].back();
//            cout << p << " ";
            res[i].pop_back();
            ans[p]++;
        }
//        cout << endl;
    }
    for(int i = 1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}