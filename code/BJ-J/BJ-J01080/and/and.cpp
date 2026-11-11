#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long ans_num;
long long max_cnt;
long long n,m;
struct st{
    long long er[100];
}e[100005];
st s[100005],ans[100005];
long long maxn;
long long sum;
void v(long long a,long long x){
    long long l[100];
    long long cnt=0;
    while(a!=0){
        cnt++;
        e[x].er[cnt]=a%2;
        s[x].er[cnt]=e[x].er[cnt];
        a/=2;
    }
    max_cnt=max(max_cnt,cnt);
    return;
}
void pl(long long a,long long b){
    for(long long i=1;i<=max_cnt;i++){
        ans[ans_num].er[i]=0;
        if(e[a].er[i]&&s[b].er[i]){
            ans[ans_num].er[i]=1;
        }
    }
    return;
}
void f(){
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            ans_num++;
            pl(i,j);
        }
    }
    for(long long i=1;i<=ans_num;i++){
        for(long long j=1;j<=max_cnt;j++){
            s[i].er[j]=ans[i].er[j];
        }
    }
}
void find_max(){
    long long q=1;
    f();
    for(long long i=1;i<=ans_num;i++){
        q=1;
        for(long long j=1;j<=max_cnt;j++){
            sum+=ans[i].er[j]*q;
            s[i].er[j]=ans[i].er[j];
            q*=2;
        }
        maxn=max(sum,maxn);
        sum=0;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        long long a;
        cin>>a;
        v(a,i);
    }
    for(long long i=1;i<m;i++){
        f();
        ans_num=0;
    }
    find_max();
    cout<<maxn;
    return 0;
}
