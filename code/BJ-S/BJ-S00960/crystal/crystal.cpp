#include<bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second

using namespace std;
const int N=5e5+10;
long long a[N];
bool vis[N];
long long cha[N];

int n;long long m;

long long f1(long long sum){
    long long cnt1=0;
    sum/=n;int tt=m;
    for(int i=1;i<=n;i++){
        if(a[i]>sum) break;
        long long c=sum-a[i];
        if(tt-c>=0) tt-=c;
        cnt1++;
    }
    return cnt1;
}

/*long long f2(){
    for(int i=1;i<=n;i++){
        cha[i]=a[i]-a[i-1];
    }
    sort(cha+1,cha+n+1);
    long long now=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(now+abs(cha[i])<=m){
            now+=abs(cha[i]),cnt++;

        }
        else break;
    }
    return cnt;
}
*/
long long f3(long long sum){
    long long cnt=0;
    vector<pii>t;
    sum/=n;
    sort(a+1,a+n+1);
    long long c=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            c++;
        }
        if(a[i]!=a[i-1]){
            if(c!=0){
                t.push_back({c,a[i-1]});
                c=0;
            }
        }
    }
    sort(t.begin(),t.end());
    if(t.size()==0) return 0;
    //for(int i=0;i<t.size();i++) cout<<t[i].sec;
    long long tar=t[0].sec,t1=m;
    for(int i=1;i<=n;i++){
        if(a[i]>tar) continue;
        long long ch=tar-a[i];
        if(t1-ch>=0) t1-=ch,cnt++;
        //cout<<a[i]<<" ";
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long sum=0,cnt1=0;
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    long long ans1=f1(sum);
    //cout<<"Yes";
    long long ans2=f3(sum);
    cout<<max(ans1,ans2);
    //cout<<ans1<<" "<<ans2;
    /*for(int i=1;i<=n;i++){
        dfs(m,1,a[i]);
        res=max(res,ans);
        ans=0;
        memset(vis,0,sizeof vis);
    }*/
    return 0;
}
