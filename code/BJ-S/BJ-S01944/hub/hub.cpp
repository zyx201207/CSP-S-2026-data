#include<bits/stdc++.h>
using namespace std;

vector<int> bian[1145140];
int dep[1145140];

void getdep(int now,int fa){
    dep[now]=dep[fa]+1;
    for(auto v:bian[now])
        if(v!=fa)
            getdep(v,now);
}

vector<int> path;bool flag[1145140];
int getpath(int now,int mb,int fa){
    if(now==mb){
        flag[now]=1;
        path.push_back(now);
        return 1;
    }
    int res;
    for(auto v:bian[now])
        if(v!=fa)
            if(res=getpath(v,mb,now)){
                flag[now]=1;
                path.push_back(now);
                return res+1;
            }
    return 0;
}

int ans[1145140];

void getans(int now,int fa){
    ans[now]=0;
    for(auto v:bian[now])
        if(v!=fa&&flag[v]==0){
            getans(v,now);
            ans[now]=max(ans[v]+1,ans[now]);
        }
}

int tong[1145140];
int zjans[1145140];
int tol[1145140],tor[1145140];

void work(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    getdep(1,0);
    int lpos=1;
    for(int i=2;i<=n;i++)
        if(dep[i]>dep[lpos])
            lpos=i;
    getdep(lpos,0);
    int rpos=1;
    for(int i=2;i<=n;i++)
        if(dep[i]>dep[rpos])
            rpos=i;
    int cnt=getpath(lpos,rpos,0);
    for(auto v:path)getans(v,0);
    // for(auto v:path)cout<<v<<' ';cout<<endl;
    // for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++)if(!flag[i])tong[ans[i]]++;
    // for(int i=0;i<cnt;i++)cout<<ans[path[i]]<<' ';cout<<endl;

    int finalans=n+10;
    for(int i=n-1;i>=0;i--)tong[i]+=tong[i+1];
    // for(int i=0;i<n;i++)cout<<tong[i]<<' ';cout<<endl;
    
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        int nowk=k-tong[mid];
        // cout<<"now:"<<mid<<' '<<nowk<<endl;
        //get tol
        int left=0,lvalue=0,notok=-1;
        for(int i=0;i<cnt;i++){
            // cout<<i<<' '<<ans[path[i]]<<' '<<(mid-1)<<' '<<ans[path[i]]+i-(mid-1)<<endl;
            if(ans[path[i]]+i-left>lvalue)left=ans[path[i]]+i-(mid-1),lvalue=mid-1,notok=max(notok,left-1);
            if(left>i)left=i+1,lvalue=0,notok=i;
            if(left<=notok)left=notok+1,lvalue=ans[path[i]]+i-left;
            tol[i]=left;
        }
        //get tor
        int right=cnt-1,rvalue=0;notok=cnt;
        for(int i=cnt-1;i>=0;i--){
            if(ans[path[i]]+right-i>rvalue)right=(mid-1)-(ans[path[i]]-i),rvalue=mid-1,notok=min(notok,right+1);
            if(right<i)right=i-1,lvalue=0,notok=i;
            if(right>=notok)right=notok-1,lvalue=ans[path[i]]+right-i;
            tor[i]=right;
        }

        // for(int i=0;i<cnt;i++)cout<<tol[i]<<' '<<tor[i]<<endl;
        int now=-1145140;
        int nowl=-1,nowr=cnt;
        for(int i=0;i<cnt;i++){
            now=max(now+1,ans[path[i]]);
            if(now>=mid)break;
            nowl=i;
        }
        now=-1145140;
        for(int i=cnt-1;i>=0;i--){
            now=max(now+1,ans[path[i]]);
            if(now>=mid)break;
            nowr=i;
        }
        // cout<<nowl<<' '<<nowr<<endl;

        int mincnt=1145140;
        for(int i=-1;i<cnt;i++){
            if(i>=0&&tol[i]>i)continue;
            if(i<cnt-1&&tor[i+1]<i+1)continue;
            
            int nowcnt=0;
            if(i>=0)nowcnt+=max(1,tol[i]-nowl-1);
            if(i<cnt-1)nowcnt+=max(1,nowr-tor[i+1]-1);
            mincnt=min(mincnt,nowcnt);
            // cout<<"at:"<<i<<' '<<nowcnt<<endl;
        }

        if(mincnt<=nowk)r=mid;
        else l=mid+1;
        
    }
    cout<<l<<endl;
    for(int i=1;i<=n;i++)bian[i].clear(),flag[i]=0,tong[i]=0;
    path.clear();

}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--)work();
}
//我要ak了吗？