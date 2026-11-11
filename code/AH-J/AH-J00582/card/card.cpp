#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500005],b[300005],t[500005],ans[500005];
int sum[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[a[i]]++;
        t[i]=sum[a[i]];
        //cout<<t[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        int last=i;
        for(int j=n;j>=1;j--){
            if(a[j]==a[i-1]){
                t[j]--;
            }
            if(t[j]>1){
                last=j;
                break;
            }
        }
        //cout<<i<<" "<<last<<endl;
        for(int j=last;j<=n;j++){
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//现在是4月2日，星期四，05：11（电脑上就这个时间），还有？分钟考试结束，我写完了会写的，也就是说，我没写不会写的。
//CCF大大的好，给我一分吧！
//洛谷上会有人把这个代码塞进CSP代码大赏吗？十分期待
//CCF大大的好，给我一分吧！
//已经15：15了，突然发现考试时的一个小时像60分钟一样长
//CCF大大的好，给我一分吧！
//我要交卷吗？
//CCF大大的好，给我一分吧！
//分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来，分来……
