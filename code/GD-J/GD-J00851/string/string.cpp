#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node{
    int len;
    char id;
};
node a[1919810];
int sum[1919810];
vector<node> b;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].id;
        sum[i]=sum[i-1]+a[i].len;
    }int yib=sum[n]/2;
    int st=0;
    for(int i=1;i<=n;i++){
        if(sum[i]>yib){
            st=i;
            if(sum[n]%2&&yib-sum[i-1]==0)b.push_back({1,a[i].id});
            else if(yib-sum[i-1]!=0)b.push_back({yib-sum[i-1]+sum[n]%2,a[i].id}),a[i].len-=yib-sum[i-1];
            break;
        }else
            b.push_back(a[i]);
    }
    int cnt=b.size()-1;
    for(int i=st;i<=n;i++){
        if(cnt==-1)break;
        if(b[cnt].len>a[i].len){
            if(b[cnt].id!=a[i].id)
                ans+=a[i].len;
            b[cnt].len-=a[i].len;
        }else{
            if(b[cnt].id!=a[i].id)
                ans+=b[cnt].len;
            a[i].len-=b[cnt].len;
            if(a[i].len!=0)i--;
            cnt--;
        }
    }
    cout<<ans;
}
/*
健忘的症状这种赶春的人 该向左或向右
你看我这手里的胭脂虫
像不像那晚春的花骨朵

洛谷关注uid1063830谢谢喵

T2不会，去做了T3，T3也不会，回来继续做T2，思考到10：06，还是不会。觉得要AFO了
10：15分，T2思路初具雏形
10：36分，T2炸了 /kel
10：45分，T2过了！

哇哈哈哈哈哈！！！！！我T2过了！！！！！！！！！！！！！！！！！！
*/
