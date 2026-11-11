#include <bits/stdc++.h>
using namespace std;
long long a[500008],cnt,len=1,m,n,ans;
pair<long long,long long>b[500008];
deque<pair<long long,long long> >q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[n+1]=a[n]+1;
    for(int i=2;i<=n+1;i++){
        if(a[i]!=a[i-1]){
            b[++cnt].first=a[i-1];
            b[cnt].second=len;
            len=1;
        }else{
            len++;
        }
    }
    n=cnt;
    cnt=0;
    len=b[1].second;
    q.push_back(b[1]);
    for(int i=2;i<=n;i++){
        if(cnt+len*(b[i].first-b[i-1].first)>m){
            long long f;
            pair<long long,long long>p;
            while(!q.empty()&&cnt+len*(b[i].first-b[i-1].first)>m){
                p=q.front();
                f=p.second*(b[i-1].first-q.front().first);
                q.pop_front();
                len-=p.second;
                cnt-=f;
            }
            long long last=m-(cnt+len*(b[i].first-b[i-1].first));
            long long can=last/(long long)(b[i].first-p.first);
            len+=can;
            cnt+=can*(b[i-1].first-p.first);
            q.push_front({p.first,can});
        }
        cnt+=len*(b[i].first-b[i-1].first);
        len+=b[i].second;
        ans=max(ans,len);
        q.push_back(b[i]);
    }
    cout<<ans<<endl;
    return 0;
}
