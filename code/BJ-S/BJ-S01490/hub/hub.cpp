#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
vector<int> a[1000010];
int D[1000010];
int fa[1000010],dep[1000010];
int n,k;
void dfs0(int x){
    dep[x]=dep[fa[x]]+1;
    for(int i:a[x]){
        if(i!=fa[x]){
            fa[i]=x;
            dfs0(i);
        }
    }
}
bool bj[1000010],B[1000010];
int lca(int x,int y){//O(n)
    for(int i=1;i<=n;i++){
        bj[i]=0;
    }
    while(x!=1){
        bj[x]=1;
        x=fa[x];
    }
    bj[x]=1;
    while(!bj[y]){
        y=fa[y];
    }
    return y;
}
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
bool vis1[1000010];
void dfs1(int x){
    vis1[x]=1;
    for(int i:a[x]){
        if(!vis1[i]&&B[i]){
            dfs1(i);
        }
    }
}
bool chk(){
    for(int i=1;i<=n;i++){
        vis1[i]=0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis1[i]&&B[i]){
            dfs1(i);
            cnt++;
        }
    }
    return (cnt<=2);
}
int dp1[1000010],dp2[1000010],dp3[1000010],dp4[1000010];
void dfsdp12(int x){
    int maxd1=0,maxd2=0;
    for(int i:a[x]){
        if(i!=fa[x]){
            dfsdp12(i);
            dp1[x]=max(dp1[x],dp1[i]+1);
            dp2[x]=max(dp2[x],dp2[i]);
            if(dp1[i]>dp1[maxd1]){
                maxd1=i;
            }
        }
    }
    for(int i:a[x]){
        if(i!=fa[x]&&i!=maxd1){
            if(dp1[i]>dp1[maxd2]){
                maxd2=i;
            }
        }
    }
    if(maxd2==0){
        dp2[x]=max(dp2[x],dp1[x]);
    }
    else{
        dp2[x]=max(dp2[x],dp1[maxd1]+dp1[maxd2]+2);
    }
}
void dfsdp34(int x){
    if(x!=1){
        dp3[x]=dp3[fa[x]];
        int maxd1=0,maxd2=0;
        for(int i:a[fa[x]]){
            if(i!=fa[fa[x]]&&i!=x){
                dp3[x]=max(dp3[x],dp2[i]);
                if(dp1[i]>dp1[maxd1]){
                    maxd1=i;
                }
            }
        }
        for(int i:a[fa[x]]){
            if(i!=fa[fa[x]]&&i!=x&&i!=maxd1){
                if(dp1[i]>dp1[maxd2]){
                    maxd2=i;
                }
            }
        }
        if(maxd1!=0){
            if(maxd2!=0)dp3[x]=max(dp3[x],dp1[maxd1]+dp1[maxd2]+2);
            dp3[x]=max(dp3[x],dp4[fa[x]]+dp1[maxd1]+1);
            dp4[x]=max(dp4[fa[x]]+1,dp1[maxd1]+2);
        }
    }
    for(int i:a[x]){
        if(i!=fa[x]){
            dfsdp34(i);
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin >> c >> t;
    if(c==13||c==14){
        while(t--){
            cin >> n >> k;
            for(int i=1;i<n;i++){
                int x,y;
                cin >> x >> y;
            }
            int m=n/2;
            if(k==n){
                cout << 0 << endl;
                continue;
            }
            if(k>=m){
                cout << 1 << endl;
                continue;
            }
            int p1=(m+2)/3;
            int p2=(p1+m)/2;
            k-=2;
            int x1=p1-1,x2=p2-p1-1,x3=m-p2-1;
            while(k--){
                if(x1>=x2&&x1>=x3){
                    x1--;
                }
                else if(x2>=x1&&x2>=x3){
                    x2--;
                }
                else{
                    x3--;
                }
            }
            //cout << m << " " << x1 << " " << x2 << " " << x3 << " ";
            cout << max({x1,x2,x3}) << endl;
        }
    }
    else if(c==7||c==11||c==12){
        //cout << "happy";cout.flush();
        while(t--){
            cin >> n >> k;
            for(int i=1;i<=n;i++){
                a[i].clear();
                dp1[i]=0;
                dp2[i]=0;
                dp3[i]=0;
                dp4[i]=0;
            }
            for(int i=1;i<n;i++){
                int x,y;
                cin >> x >> y;
                a[x].emplace_back(y);
                a[y].emplace_back(x);
            }
            dfs0(1);
            dfsdp12(1);
            dfsdp34(1);
            int ans=1e18;
            for(int i=1;i<=n;i++){
                vector<int> vec;
                for(int j:a[i]){
                    //cout << i;cout.flush();
                    if(j!=fa[i]){
                        //cout << i << " " << j;cout.flush();
                        vec.emplace_back(max(dp1[j]+1,dp2[j]));
                    }
                    else{
                        //cout << i << " " << j;cout.flush();
                        vec.emplace_back(max(dp4[i],dp3[j]));
                    }
                }
                //cout << vec.size();cout.flush();
                sort(vec.begin(),vec.end());
                //cout << vec.size();cout.flush();
                int tmpans=(vec[0]+1)/2;
                if(vec.size()>1){
                    tmpans=max(tmpans,vec[1]);
                }
                ans=min(ans,tmpans);
            }
            cout << ans << endl;
        }
    }
    else{
        while(t--){
            cin >> n >> k;
            for(int i=1;i<=n;i++){
                a[i].clear();
            }
            for(int i=1;i<n;i++){
                int x,y;
                cin >> x >> y;
                a[x].emplace_back(y);
                a[y].emplace_back(x);
            }
            dfs0(1);
            int R=(1<<n)-1;
            int ans=1e18;
            for(int s=0;s<=R;s++){
                if(__builtin_popcount(s)!=k){
                    continue;
                }
                for(int i=1;i<=n;i++){
                    D[i]=1e18;
                    B[i]=0;
                }
                for(int i=1;i<=n;i++){
                    if((s>>(i-1))&1){
                        for(int j=1;j<=n;j++){
                            D[j]=min(D[j],dis(i,j));
                        }
                        B[i]=1;
                    }
                }
                int tmpans=0;
                for(int i=1;i<=n;i++){
                    tmpans=max(tmpans,D[i]);
                }
                if(chk())ans=min(ans,tmpans);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
