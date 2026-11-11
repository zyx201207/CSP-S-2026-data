#include<iostream>
#include<algorithm>
using namespace std;
long long n,box[100005];
bool suba=1,subb=1;
long long m,a[500005],mxa=-2e15,mx=-2e15;
void dfs(int pos,int step){
    if(step==m){
        for(int j=1;j<=mxa;j++){
            box[j]=0;
        }
        for(int i=1;i<=n;i++){
            box[a[i]]++;
        }
        for(int i=1;i<=mxa;i++){
            mx=max(mx,box[i]);
        }
        return;
    }
    a[pos]++;
    for(int i=pos;i<=n;i++){
        dfs(i,step+1);
    }
    a[pos]--;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) suba=false;
        mxa=max(mxa,a[i]);
    }
    for(int i=2;i<=n-1;i++){
        if(a[i+1]-a[i]!=a[i]-a[i-1]) subb=false;
    }
    if(suba){//#13-15,15pts
        long long sum=0;
        for(int i=1;;i++){
            long long t=sum;
            sum+=i;
            if(sum>m){
                cout<<i;
                return 0;
            }
        }
    }
    else if(subb){//#16-18,15pts
        long long sum=0;
        long long d=abs(a[2]-a[1]);
        for(int i=1;;i++){
            long long t=sum;
            sum+=d*i;
            if(sum>m){
                cout<<i;
                return 0;
            }
        }
    }
    else{//#1-5(6-9?),25or45pts
        for(int i=1;i<=n;i++){
            long long d[5005];
            for(int j=1;j<=n;j++){
                d[j]=abs(a[i]-a[j]);
            }
            sort(d+1,d+n+1);
            long long sum=0,cnt=1;
            for(int j=2;j<=n;j++){
                sum+=d[j];
                if(sum>m) break;
                cnt++;
            }
            mx=max(mx,cnt);
        }
        cout<<mx;
    }
    return 0;
}
//aim to get 55or75pts
//join my minecraft server!!
