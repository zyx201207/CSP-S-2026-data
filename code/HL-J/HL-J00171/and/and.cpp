#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m,choice[200005],cnt,val,ans;
bool maze[200005][32];
void check(int x,int pos){
    int t = 1;
    while(x){
        maze[pos][t++] = x % 2;
        x /= 2;
    }
}bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        check(a[i],i);
    }for(int i = 31;i >= 1;i++){
        cnt = 0;
        for(int j = 1;j <= n;i++){
            if(maze[j][i]){
                cnt++;
                choice[++val] = j;
            }
        }if(cnt >= m){
            break;
        }
    }sort(choice+1,choice+val+1,cmp);
    ans = choice[1];
    for(int i = 2;i <= m;i++){
        ans &= choice[i];
    }cout << ans;
    return 0;
}
