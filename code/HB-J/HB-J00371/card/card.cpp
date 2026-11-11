#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],lst[500010],islst[500010],dp[500010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        lst[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        islst[lst[i]]=1;
    }
    for(int i=1;i<=n;i++){
        dp[a[i]]++;
        if(islst[i-1]){
            dp[a[i]]+=dp[a[i-1]];
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d",dp[i]);
        if(i!=m){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
/*
g++ card.cpp -o exe -Wall -O2
./exe
diff card.out card.ans

*/

/*
Qu(4) Mai(3)<Hao(3) Gu(1) Niang(0) Guang(1) Mang(2) Wan(4) Zhang(4)>
*/

/*
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
WYF who falls in love with BSK is not in this group.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
Ai Chi Bi Sheng Ke De WYF Bu Zai Ci Dui.
*/