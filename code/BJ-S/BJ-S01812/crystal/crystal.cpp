#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],st[N],pos[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        st[i] = a[i] + m;
    }
    for(int i = 1;i <= n;i++){
        pos[i] = n;
        for(int j = n;j > i;j--){
            if(st[i] >= a[j]){
                pos[i] = j;
                break;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        //printf("%d ",pos[i]);
    }
    //printf("\n");
    for(int i = 1;i <= n;i++){
        for(int j = pos[i];j > i;j--){
            bool flag = 1;
            int t = m;
            for(int k = 1;k < j;k++){
                t -= a[k];
                if(t < 0){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                printf("%d\n",j - i + 1);
                return 0;
            }
        }
    }
    return 0;
}
/*5 8
-3 -1 2 2 7*/
