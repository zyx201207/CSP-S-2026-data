#include<bits/stdc++.h>
using namespace std;
int n;long long m;
long long a[500100];
int x;
//额的神啊，我终于想出来正解了，贪心模拟遍历！！！
//可惜还得做其他题解释不了，时间戳16:22:24
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long sum=0;int num=1,total=1;
    for (int i=2;i<=n;i++){
        total++;
        sum+=(a[i]-a[i-1])*(i-num);
        while(sum>m){
            sum-=a[i]-a[num];
            num++;
            total--;
        }
        x=max(x,total);

    }
    printf("%d",x);
	return 0;
}
