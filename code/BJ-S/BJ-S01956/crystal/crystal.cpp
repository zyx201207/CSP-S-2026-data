#include <bits/stdc++.h>

using namespace std;

inline long long read(){
    long long f=1,sum=0;
    char c=getchar();
    while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
    return f*sum;
}
long long n,m;
struct node{
    long long x;
    int y;//num
}a[500005];
long long b[500005];
int cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)b[i]=read();
    sort(b+1,b+1+n);
    int cnt1=1;
    for(int i=1;i<=n;i++){
        if(b[i]==b[i+1]){
            cnt1++;
        }else{
            a[++cnt].x=b[i];
            a[cnt].y=cnt1;
            cnt1=1;
        }
    }
    queue <int> q;
    for(int j=1;j<=a[1].y;j++)q.push(1);
    int ans=a[1].y;
    long long sum=0;
    int now=a[1].x;
    int maxans = a[1].y;
    for(int i=2;i<=cnt;i++){
        if(sum+ans*(a[i].x-now)<=m){
            sum+=ans*(a[i].x-now);
            ans+=a[i].y;
            now = a[i].x;
            maxans = max(ans,maxans);
            for(int j=1;j<=a[i].y;j++)q.push(i);
        }else if(a[i].x-now<=m){
            sum+=ans*(a[i].x-now);
            now = a[i].x;
            ans+=a[i].y;
            while(sum>m){
                int tp=q.front();
                q.pop();
                sum-=(a[i].x-a[tp].x);
                ans--;
            }
            maxans = max(ans,maxans);
        }else{
            while(!q.empty())q.pop();
            for(int j=1;j<=a[i].y;j++)q.push(i);
            int ans=a[i].y;
            long long sum=0;
            int now=a[i].x;
            maxans = max(ans,maxans);
        }
    }cout<<maxans;
    return 0;
}
