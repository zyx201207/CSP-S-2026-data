#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int nd=0;
    for(int S=29;S>=0;S--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=nd){
                if(a[i]&(1<<S)){
                    cnt++;
                }
            }
        }
        if(cnt>=m){
            nd=nd+(1<<S);
        }
    }
    printf("%d\n",nd);
    return 0;
}
/*
g++ and.cpp -o exe -Wall -O2
./exe
diff and.out and.ans

*/


/*
Qu(4) Mai(3)<Hao(3) Gu(1) Niang(0) Guang(1) Mang(2) Wan(4) Zhang(4)>
*/

/*
Feng Dao Zhe Li Jiu Shi Nian
Nian Zhu Guo Ke De Si Nian
Yu Dao Zhe Li Chan Cheng Xian
Chan Zhe Wo Men Liu Lian Ren Shi Jian
Ni Zai Shen Bian Jiu Shi Yuan
Yuan Fen Xie Zai San Sheng Shi Shang Mian
Ai You Wan Fen Zhi Yi Tian
Ning Yuan Wo Jiu Zang Zai Zhe Yi Dian

6c
Tian Tian Nian Nian Tian Tian De Wo
Shen Shen Kan Ni De Lian
Sheng Qi De Wen Rou
Man Yuan De Wen Rou De Lian
*/

/*
ICPC Wuhan 2026
*/