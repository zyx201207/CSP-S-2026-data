#include <bits/stdc++.h>
using namespace std;

int c,T;
int n,k;
vector<int> to[3000+10];
bool tp[3000+10];

int isin(vector<int> v,int num){
    int le=0,ri=v.size()-1;
    while(le<=ri){
        int mid=(le+ri)/2;
        if(v[mid]==num)return mid;
        else if(v[mid]>num)ri=mid-1;
        else le=mid+1;
    }return -1;
}

int check(){
    bool isin[3000]={0};
    int z;
    for(int i=1;i<=n;i++)if(tp[i]){
        z=i;break;
    }
    queue<int> res;
    res.push(z);
    while(!res.empty()){
            int x=res.front();res.pop();
        for(auto y:to[x]){
            if(isin[y])continue;
            if(!tp[y])continue;
            isin[y]=1;res.push(y);
        }
    }

    z=-1;
    for(int i=1;i<=n;i++)if(tp[i]&&!isin[i]){
        z=tp[i];break;
    }if(z==-1)return 1;
     res.push(z);
    while(!res.empty()){
            int x=res.front();res.pop();
        for(auto y:to[x]){
            if(isin[y])continue;
            if(!tp[y])continue;
            isin[y]=1;res.push(y);
        }
    }
    for(int i=1;i<=n;i++)if(tp[i]&&!isin[i])return 0;
    return 1;
}

pair<int,int> dfsp(int x,int fa,int las){
    pair<int,int> ans{0,0x3f3f3f3f};
    for(auto y:to[x]){
        pair<int,int> tmp=dfsp(y,x,(tp[x]?1:las+1));
        ans.first=max(ans.first,tmp.first);
        ans.second=min(ans.second,tmp.second+1);
    }
    if(tp[x])return{ans.first,0};
    return {max(ans.first,max(las,ans.second)),ans.second};
}

int score(){
    return dfsp(1,0,0).first;
}

int dfs(int maxp,int num){
    if(num==k){
        if(check())return score();
        else return 0x7f7f7f7f;
    }

    int ans=0x7f7f7f7f;
    for(int i=maxp+1;i<=n;i++){
        tp[i]=1;
        ans=min(ans,dfs(i,num+1));
        tp[i]=0;
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c>>T;
    while(T--){
        cin >> n >> k;
        for(int i=1;i<n;i++){
            int x,y;cin >> x>>y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        cout << dfs(0,0)<<endl;
    }
    return 0;
}
