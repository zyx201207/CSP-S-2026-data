#include <bits/stdc++.h>
using namespace std;

int ans=0;
int n,k;
vector<int>a,b;
void solve(){
    b=a;
//    for (int i:b){
//        printf("%d ",i);
//    }
    for (int i=30;i>=0;i--){
        int cnt=0;
        for (int j:b){
 //           printf("%d(%d) ",j,j&(1<<i));
            if ((j&(1<<i))>0)cnt++;
        }
 //       printf("%d\n",cnt);
        if (cnt>=k){
            ans+=(1<<i);
            a.clear();
            n=0;
            for (int j:b){
                if ((j&(1<<i) && j!=(1<<i))>0){
                    a.push_back(j-(1<<i));
                    n++;
                }
            }
            return ;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    while (n>=k){
        solve();
 //       printf("%d\n",n);
    }
    printf("%d",ans);
    return 0;
}
//Desktop/HB-J00569/and/and.cpp >heLLo
