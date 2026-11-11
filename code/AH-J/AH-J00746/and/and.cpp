#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m,h,mx;
bool a[200005][31];
int a_[200005];
vector<int> b;
bool vis[200005],t[200005];
void g(int step,int an){
    if(step==m){
        mx=max(mx,an);
        return;
    }
    for(int i=0;i^b.size();i++){
        if(t[i])continue;
        t[i]=1;
        g(step+1,an&a_[b[i]]);
        t[i]=0;
    }
}
int f(int st){
    int last=b.size();
    for(st;st^0,last>=m;st--){
        memcpy(t,vis,sizeof(t));
        for(int i=0;i^b.size();i++){
            if(!a[b[i]][st])vis[b[i]]=1,last--;
        }
    }if(!st){
        for(int i=0;i^b.size();i++){
            if(!t[i])return a_[b[i]];
        }
    }else{
        g(0,(1<<30)-1);
        return mx;
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1,x,j=0;i<=n;i++,j=0){
        scanf("%d",&x);
        a_[i]=x;
        while(x){
            a[i][++j]=(x&1);
            x>>=1;
        }h=max(h,j);
    }for(h;h^0;h--){
        b.clear();
        int s=0;
        for(int i=1;i<=n;i++){
            if(a[i][h])b.push_back(i),s++;
        }if(s<m)continue;
        //for(int i=0;i^b.size();i++)cout<<a_[b[i]]<<" ";
        //cout<<endl;
        cout<<f(h-1);
        break;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
