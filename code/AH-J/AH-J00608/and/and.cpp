#include <bits/stdc++.h>
#define int long long
#define N 200005
#define M 1048580
using namespace std;
int n,m,a[N];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
void work1(){//m=1
    int maxx=-1;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
}
void work2(){//m=n
    int sum=a[1];
    for(int i=2;i<=n;i++){
        sum&=a[i];
    }
    cout<<sum;
}
void work3(){//m=2
    int maxx=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)maxx=max(maxx,a[i]&a[j]);
    }
    cout<<maxx;
}
void work4(){//m=n-1
//    int t[M]={0};
	int sum=0,maxx=-1,f=0;
    for(int i=1;i<=n;i++){
//        if(!t[a[i]]){
            sum=0;
//            t[a[i]]=1;
            f=0;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    if(!f)f=1,sum=a[j];
                    else sum&=a[j];
                }
            }
            maxx=max(maxx,sum);
//        }
    }
    cout<<maxx;
}
void work5(){//A
    int sum=a[n];
    sort(a+1,a+n+1);
    for(int i=n-1,j=2;j<=m;i--,j++)sum&=a[i];
    cout<<sum;
}
int dfs(int k,int ans,int x){
    if(x==m)return ans;
    if(k==n+1||n-k+1<m-x)return -1;
    if(!x)return max(dfs(k+1,a[k],x+1),dfs(k+1,0,x));
    if(!ans)return 0;
    return max(dfs(k+1,ans&a[k],x+1),dfs(k+1,ans&a[k],x));
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(m==1)work1();
    else if(m==n)work2();
    else if(m==2)work3();
    else if(m==n-1)work4();
    else work5();
    return 0;
}
