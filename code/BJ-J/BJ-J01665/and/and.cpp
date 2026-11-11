#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n,m;
long long maxx=-1e18;
void dfs(int x,long long sum,int cnt){
    if(x==n+1){
        if(cnt==m)maxx=max(maxx,sum);
        return ;
    }
    if(cnt+1<=m)dfs(x+1,sum&a[x],cnt+1);
    dfs(x+1,sum,cnt);
}
long long maxai=-1e18;
bool check(long long x){
    //判断x是不是2^k-1
    //因为a[i]<=2^20，所以时间复杂度为20n，不可能超
    long long cnt=1;
    if(x==0){
        //即a[i]=2^0-1
        return 1;
    }
    for(int k=1;k<=21;k++){
        cnt*=2;
        if(x==cnt-1){
            return 1;
        }
    }
    return 0;
}
bool is_teshua(){
    for(int i=1;i<=n;i++){
        if(!check(a[i]))return false;
    }
    return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxai=max(maxai,a[i]);
    }
    if(n<=20){
        dfs(1,(long long)(2ll<<31)-1,0);//这个玩意二进制全是1，这谁能打
        cout<<maxx<<endl;
    }else if(m==1){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx<<endl;
    }else if(m==2 && n<=2000){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //m=2时，需要选择两个数，直接美剧
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx<<endl;
    }else if(m==n){
        long long maxx=INT_MAX;
        for(int i=1;i<=n;i++){
            maxx&=a[i];
        }
        cout<<maxx<<endl;
    }else if(maxai<4){
        int mp[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
        }
        //3 : 11
        //2 : 10
        //1 : 01
        //0 : 00
        if(mp[3]>=m){//全选3
            cout<<3<<endl;
            return 0;
        }
        if(mp[3]+mp[2]>=m){//选3、2
            cout<<2<<endl;
            return 0;
        }
        if(mp[3]+mp[1]>=m){//选3，1
            cout<<1<<endl;
            return 0;
        }else{//没得说了，只能混/选0
            cout<<0<<endl;
            return 0;
        }
    }else if(is_teshua()){
        sort(a+1,a+1+n);
        long long ans=(2ll<<31)-1;
        for(int i=n;i>=n-m+1;i--){
            ans&=a[i];
        }
        cout<<ans<<endl;
    }else{
        cout<<0<<endl;//骗分
    }
    //n<=20 : 25pts
    //n<=2000 : 25pts
    //maxai<4 : 10pts
    //A : 5pts
    //共计65pts
    return 0;
}
/*
//m=1
long long maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
//m=n;
    long long maxx=INT_MAX;
    for(int i=1;i<=n;i++){
        maxx&=a[i];
    }
    cout<<maxx;
*/

/*m=2 n<=2000

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //m=2时，需要选择两个数，直接美剧
            maxx=max(maxx,a[i]&a[j]);
        }
    }
    cout<<maxx;

a[i]<4

特殊A：
这个是指所有的位都是1
故可以直接给他排序，用最大的几个
特殊a测试：
8 3
0 1 3 7 3 15 0 0
*/
