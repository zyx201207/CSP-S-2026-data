#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int n,caseid,fa[2005000],dfn[2005000],de[2005000],tot=0,sz[2005000],mx[2005000],rdfn[2005000]
,mn[2005000];
long long A[2005000],d,ans=0;
vector<int>t[2005000];
vector<int>D[2005000];
void dfs(int x){
    sz[x]=1;
    dfn[x]=++tot;
    rdfn[tot]=x;
    de[x]=de[fa[x]]+1;
    mx[de[x]]=mx[de[x]+1]=0;
    mn[de[x]]=mn[de[x]+1]=n;
    for(int i=0;i<t[x].size();i++){
        int v=t[x][i];
        dfs(v);
        sz[x]+=sz[v];
    }
}
void dfs2(int x,int f0,int f1,int id){
    //cerr<<x<<" "<<f0<<" "<<f1<<" "<<id<<endl;
    ans+=f1;
    int F0=f0,F1=f1;
    mx[de[x]]=max(mx[de[x]],dfn[x]);
    mn[de[x]]=min(mn[de[x]],dfn[x]);
   // D[de[x]].push_back(dfn[x]);
    if(id==0){
        F0++;
        if(F1){
            if(t[fa[fa[x]]][0]==fa[x]||
               sz[t[fa[fa[x]]][0]]==1){
                F1=f1;
               }else{
                F1=0;
               }
        }
    }else if(id==1){
        F0=id+1;
        F1=f0;
    }else if(id>1){
        F0=id+1;
        F1=0;
    }
    if(t[x].size()==0)return;
    int flag=0;
    for(int i=t[x].size()-1;i>=0;i--){
        int v=t[x][i];
        dfs2(v,F0,F1,i);
        if(sz[v]==1&&flag==0){
            F0++;
        }else{
            flag=1;
        }
    }
}
void solve(int testid){
    cin>>n>>d;
    tot=0;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        mx[i]=0;
        mn[i]=n;
        de[i]=0;
    }
    vector<int>root;
    for(int i=1;i<=n;i++){
        fa[i]=upper_bound(A+1,A+1+n,A[i]+d)-A-1;
        if(fa[i]!=i)t[fa[i]].push_back(i);
        else root.push_back(i);
    }
    for(int j=0;j<root.size();j++){
    int n2=root[j];
    dfs(n2);
    dfs2(n2,0,0,0);
    for(int i=2;i<=n2;i++){
        if(mx[i]==0){
             //   cerr<<"%"<<i<<endl;
                break;}
        //sort(D[i].begin(),D[i].end());
        if(fa[rdfn[mx[i]]]==fa[rdfn[mn[i]]])continue;
        int X=rdfn[mx[i]];
        int N=rdfn[mn[i-1]];
        if(t[fa[X]].size()>1)continue;
        int tmp=mx[i]-1;
        while(de[rdfn[tmp]]==i-1){
            tmp--;
        }
        tmp++;
        int len=mx[i]-1-tmp+1;
        long long ex=0;
        if(sz[X]==1){
            ex=sz[N]-1;
        }else{
            ex=t[N].size();
        }
        ans+=ex*len;
    }/*
    for(int i=2;i<=n2;i++){
        if(mx[i]==0)break;
        if(sz[D[i][0]]!=1)continue;
        int X=rdfn[mx[i]];
        if(sz[X]!=1)continue;
        int tmp=mx[i];
        while(de[rdfn[tmp]]==i){
            tmp--;
        }
        tmp++;
        int len=mx[i]-tmp+1;
        long long ex=0;
            ex=sz[D[i][1]]-1;
        ans+=ex*len;
        cerr<<"#"<<i<<" "<<ex<<" "<<len<<endl;
    }*/
    for(int i=2;i<=n2;i++){
        if(mx[i]==0)break;
        D[i].clear();
    }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)t[i].clear();
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>caseid>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
