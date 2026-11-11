#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N=(int) 2*1e5+10;
long long a[N];
bool f[N];
long long mx;
int d[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
void dfs(long long x,long long y,long long xy){
    if(x==m+1){
        mx=max(mx,y);
        return ;
    }
    for(long long i=xy+1;i<=n;i++){
        if(f[i]==0){
            long long t1=a[i],t2=y,temp=0;
            long long quan=1;
            while(t1>0&&t2>0){
                if(((t1%2)==1)&&((t2%2)==1)){
                    temp+=quan;
                }
                quan*=2;
                t1/=2;
                t2/=2;
            }
            f[i]=1;
            dfs(x+1,temp,i);
            f[i]=0;
        }
    }
}
bool flag;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        bool tt=0;
        for(long long j=0;j<21;j++){
            if(a[i]==d[j]-1){
                tt=1;
                break;
            }
        }
        if(tt==0){
            flag=1;
        }
    }
    if(flag==0){
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
        return 0;
    }
    if(m==n-1){
        for(long long i=1;i<=n;i++){
            long long temp;
            if(i==1){
                temp=a[2];
            } else{
                temp=a[1];
            }
            for(long long j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                long long t1=temp,t2=a[j],zui=0;
                long long quan=1;
                while(t1>0&&t2>0){
                    if(((t1%2)==1)&&((t2%2)==1)){
                        zui+=quan;
                    }
                    quan*=2;
                    t1/=2;
                    t2/=2;
                }
                temp=zui;
            }
            mx=max(mx,temp);
        }
        cout<<mx;
        return 0;
    }
    for(long long i=1;i<=n-m+1;i++){
            f[i]=1;
            dfs(2,a[i],i);
            f[i]=0;
    }
    cout<<mx;
    return 0;
}
