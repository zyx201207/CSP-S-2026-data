/*
1414:提前进场了，居然给每个人都在大电脑下面分配了一个小电脑。目前来看虚拟机状态良好。
一年一度秋风劲，不胜春光，胜似春光，辽阔江天万里霜。
加油吧！
左侧，小朋友：《老师这个电脑为什么打不开阿》
《我不小心把他合上了》
监考老师有口音，多次被打断施法（即宣读规则）
我去，左边的小朋友跑了！
1430:Oct31==Dec25?
1431:subway?
1432:不开freopen司马。开A！
1434:大概看懂了。
1435:性质A显然，直接输出n。
1436:先说O(n^2)吧。因为只能加不能减，所以最后一定是加到一个i。
枚举这个i，然后从i往后减，看行不行。
1438:改这个为二分，即可。
1443:无敌了死机了。
1444:想得不全面，会被卡。
1448:先写朴素吧，我怕出现去年那样的情况。
1451:写完了。能对。
现在考虑，外面不能log，里面可以马？
里面考虑前面弄个后缀和，然后统一减个当前数，就可以二分了。
1459:100pts get.
1500:老师说了，写一提较一体，所以，替教。
*/

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        long long cnt=0,tmpm=m;
        long long l=1,r=i;
        while(l<=r){
            long long mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=tmpm)cnt=(i-mid+1),r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}