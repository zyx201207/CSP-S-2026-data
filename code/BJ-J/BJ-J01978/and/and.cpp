#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int f=1,sum=0;
    char c=getchar();
    while(!(c<='9'&&c>='0')){if(c=='-')f=-1;c=getchar();}
    while(c<='9'&&c>='0'){sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
    return f*sum;
}
int n,m;
int a[200005];
//& and
int maxx=0;
int b[200005];
int c[200005];
void dfs(int now,int num,int tot){
    if(tot<maxx||tot==0)return ;
    if(num==m){
        maxx = max(maxx,tot);
    }
    if(m-num>n-now)return;
    for(int i=now;i<=n-num;i++){
        dfs(i+1,num+1,tot&a[i]);
    }
}
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();m=read();
    bool flag1=true;
    bool flag2=true;
    if(((n-1)&n)!=0)flag2=false;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(((a[i]+1)&a[i])!=0)flag1=false;
        if(a[i]!=i-1)flag2=false;
    }
    int ans=0;
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans = (ans&a[i]);
        cout<<ans;
        return 0;
    }if(flag1){
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
        return 0;
    }if(flag2){
        ans = a[n];
        for(int i=n-1;i>=n-m+1;i--)ans = (ans&a[i]);
        cout << ans;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        dfs(i+1,1,a[i]);
    }
    cout<<maxx<<endl;
    return 0;
}
