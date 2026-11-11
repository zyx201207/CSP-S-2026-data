#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
int n,m;
int a[N];
int cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int z = 1;z<=n;z++){
        vector<int> v;
        for(int i = z;i<=n;i++){
            for(int j = n;j>i;j--){
                if(a[i]==a[j]){
                    i=j;
                    break;
                }
            }
            v.push_back(a[i]);
        }
        for(int i : v){
            cnt[i]++;
        }
    }
    for(int i = 1;i<=m;i++){
        printf("%d ",cnt[i]);
    }
}
