#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d,x[2000010],ll[2000010],rr[2000010],res;
inline int mfind(int i){
    int l=i,r=n,best=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(x[mid]-x[i]<=d){
            best=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return best;
}
inline int getdis(int xx,int y){
    int cur=xx,dis=0;
    while(y>cur){
        cur=rr[cur],dis++;
        if(cur==rr[cur]&&cur<y)return -1;
    }
    return dis;
}
inline bool bfs(int s,int t){
    queue<pair<int,int> >q;
    int mn=getdis(s,t),cnt=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.front().first,dis=q.front().second;
        //cout<<u<<"\n";
        q.pop();
        if(dis>mn)continue;
        if(dis+getdis(u,t)>mn)continue;
        if(u==t){
            cnt++;
            if(cnt>2)return false;
            continue;
        }
        for(int v=u+1;v<=rr[u];v++){
            q.push({v,dis+1});
        }
    }
    return cnt==2;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&d);res=0;
        for(int i=1;i<n;i++){
            scanf("%lld",&x[i]);
            scanf("%lld",&x[i]);
            ll[i]=rr[i]=0;
        }
        int gap=1;
        for(int i=1;i<=n;i++){
            int k=mfind(i);
            rr[i]=k;
            if(!ll[k])ll[k]=i;
            if(!ll[i])ll[i]=gap;
            if(i==k)gap=i+1;
        }
        //for(int i=1;i<=n;i++)cout<<ll[i]<<" "<<rr[i]<<"\n";
        /*
        gap=1;
        for(int i=rr[1];i<=n;i++){
            int len=ll[i]-gap+1;
            cout<<i<<" nowgap:"<<gap<<" "<<len<<" nowcontuibute:"<<rr[i-1]-i<<"\n";
            res+=(len*(rr[i-1]-i));
            if(rr[i]==i){
                gap=i+1;
                if(gap>n)break;
                i=rr[gap]-1;
            }
        }*/
        /*
        gap=n;
        for(int i=n;i>=1;i--){
            /*if(rr[i]>ll[gap]){
                res+=gap-rr[i];
                cout<<"get1:"<<gap-rr[i]<<" "<<i<<"\n";
            }*//*
            if(i<=ll[gap]){
                res+=s[rr[i]];
                //cout<<"get2:"<<s[rr[i]]<<" "<<i<<"\n";
                s[i]=s[rr[i]]+rr[i-1]-rr[i-2];
            }
            if(i==ll[i])gap=i-1;
            //for(int j=1;j<=n;j++)cout<<s[j]<<" ";
            //puts("");
        }*/
        for(int i=1;i<=n;i++){
            for(int j=rr[i]+1;j<=n;j++){
                if(getdis(i,j)==-1)continue;
                if(bfs(i,j))res++;
            }
        }

        printf("%lld\n",res);
    }
    return 0;
}
/*
0 1
6 3
0 1 2 3 4 7
*/
