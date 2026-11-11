#include <bits/stdc++.h>
using namespace std;

int a[500010];
int lst[300010];
vector<int>pos[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool speA=1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        lst[a[i]]=i;
        pos[a[i]].push_back(i);
        if (i>1 && a[i-1]>a[i])speA=0;
    }
    if (speA){
        for (int i=1;i<=m;i++){
            printf("%d\n",lst[i]);
        }
        return 0;
    }

    return 0;
}
//Desktop/HB-J00569/card/card.cpp >hellO
