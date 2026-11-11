#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

int main(){
    //freopen("hub.in","r",stdin);
    //freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    for(int tt = 0;tt < t;tt++){
        int n,k;
        scanf("%d %d",&n,&k);
        vector<pair<int,int> > v(n);
        for(int i = 0;i < n;i++){
            scanf("%d %d",&v[i].first,&v[i].second);
        }
        int t = 0;
        while(n > 0){
            n >>= 0;
            t++;
        }
        printf("%d\n",2 * t - 1);
    }
    return 0;
}
