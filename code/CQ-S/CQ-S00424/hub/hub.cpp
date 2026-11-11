/*
50pts，力竭了
F,只有15pts了 呜呜呜
*/
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
    char*p1,*p2,buf[1<<21];
    #define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
    void read(int&x){
        x=0;char ch;int h = 1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x *= h;
    }
    void write(int x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]] = x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void read(char&x){do x=getchar();while(x==' '||x=='\n'||x=='\r');}
    void write(char x){putchar(x);}
    void write(int x,char y){write(x);write(y);}
    #ifndef int
    void read(long long&x){
        x=0;char ch;int h = 1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x *= h;
    }
    void write(long long x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]] = x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void write(long long x,char y){write(x);write(y);}
    #endif
namespace gtx{
    const int MAXN = 1e6+10;
    int n,k;
    vector<int> v[MAXN];
    int f[MAXN];
    int lim;
    int maxdis[MAXN];
    void dfs(int k,int fath){
        maxdis[k] = 0;
        int maxdis1 = 0;
        f[k] = 0;
        for(int i:v[k]){
            if(i==fath) continue;
            dfs(i,k);
            f[k] += f[i];
            if(maxdis[i]+1>maxdis[k]){
                maxdis1 = maxdis[k];
                maxdis[k] = maxdis[i]+1;
            }else if(maxdis[i]+1>maxdis1) maxdis1 = maxdis[i]+1;
        }
        if(f[k]) f[k]++;
        if(!f[k]){
            if(maxdis[k]+maxdis1>lim){
                f[k] = 1;
            }
            if(maxdis[k]==lim&&fath){
                f[k] = 1;
            }
        }
    }
    int dfs2(int k,int fath,int F){
        if(F>lim) return 0x3f3f3f3f;
        int maxdis1=0,maxdis2 =0 ;
        for(int i:v[k]){
            if(i==fath) continue;
            if(maxdis[i]+1>maxdis1){
                maxdis2 = maxdis1;
                maxdis1 = maxdis[i]+1;
            }else if(maxdis[i]+1>maxdis2){
                maxdis2 = maxdis[i]+1;
            }
        }
        int res = max(f[k],1);
        for(int i:v[k]){
            if(i==fath) continue;
            res = min(res,dfs2(i,k,max(F+1,maxdis[i]+1==maxdis1?maxdis2+1:maxdis1+1)));
        }
        return res;
    }
    int dfs1(int k,int fath,int F){
        int tot=0,is;
        int maxdis1 = 0,maxdis2 = 0;
        for(int i:v[k]){
            if(i==fath) continue;
            if(maxdis[i]+1+F>lim){
                tot++;
                is = i;
                if(maxdis[i]+1>maxdis1){
                    maxdis2 = maxdis1;
                    maxdis1 = maxdis[i]+1;
                }else if(maxdis[i]+1>maxdis2){
                    maxdis2 = maxdis[i]+1;
                }
            }
        }
        // cout << "====== " << k << " " << fath << " " << F << " " << tot << endl;
        if(F>lim) return dfs2(k,fath,0);
        if(tot==0) return 0;
        if(tot==1){
            return dfs1(is,k,F+1);
        }
        int res = 0x3f3f3f3f;
        for(int i:v[k]){
            if(i==fath) continue;
            res = min(res,dfs2(i,k,maxdis[i]+1==maxdis1?maxdis2+1:maxdis1+1));
        }
        return res;
    }

    bool check(int x){
        // cout << "checking " << x << endl;
        lim = x;
        for(int i = 1;i<=n;i++){
            dfs(i,0);
            if(f[i]<=k) return true;
            // cout << i << endl;
            // cout << "------" << endl;
            // cout << f[i] << endl;
            for(int j:v[i]){
                if(f[i]-f[j]>k) continue;
                // cout << j << " " << f[i]-f[j] << endl;
                if(f[i]-f[j]+dfs1(j,i,1)<=k) return true;
            }
        }
        return false;
    }
    signed main(){
        read(n);read(k);
        for(int i= 1;i<=n;i++) v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y;
            read(x);read(y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        // cout << check(1) << endl;
        int L = 0,R = n-1,res = 0;
        while(L<=R){
            int mid = (L+R)>>1;
            if(check(mid)){
                res = mid;
                R = mid-1;
            }else L = mid+1;
        }
        write(res,endl);
        return 0;
    }
}

namespace gtx2{
    const int MAXN = 1e6+10;
    int n,k;
    vector<pair<int,int>> ms;
    int fath[MAXN];
    int get_father(int x){
        if(fath[x]==x) return fath[x];
        return fath[x] = get_father(fath[x]);
    }
    int mark[MAXN];
    int res = 0;
    int dis[MAXN];
    vector<int> v[MAXN];
    void dfs(int now){
        if(!k){
            int tot = 0;
            for(int i = 1;i<=n;i++){
                tot += mark[i];
            }
            for(pair<int,int> i:ms){
                int a = i.first;
                int b = i.second;
                tot -= mark[a]&&mark[b];
            }
            if(tot<=2){
                queue<int> q;
                for(int i = 1;i<=n;i++){
                    dis[i] = -1;
                    if(mark[i]){
                        dis[i] = 0;
                        q.push(i);
                    }
                }
                int maxdis = 0;
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    maxdis = max(maxdis,dis[x]);
                    for(int i:v[x]){
                        if(dis[i]==-1){
                            dis[i] = dis[x]+1;
                            q.push(i);
                        }
                    }
                }
                res = min(res,maxdis);
                // if(maxdis==1){
                //     for(int i = 1;i<=n;i++){
                //         if(mark[i]){
                //             cout << i << endl;
                //         }
                //     }
                //     cout << endl;
                // }
            }
            return;
        }
        if(now==n+1) return;
        k--;mark[now] =1 ;
        dfs(now+1);
        k++;mark[now] = 0;
        dfs(now+1);
    }
    signed main(){
        read(n);read(k);
        for( int i = 1;i<=n;i++) v[i].clear();
        ms.clear();
        for(int i = 1;i<n;i++){
            int x,y;
            read(x);read(y);
            v[x].push_back(y);
            v[y].push_back(x);
            ms.push_back({x,y});
        }
        res = 0x3f3f3f3f;
        dfs(1);
        write(res,endl);
        return 0;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int T = 1;
    int c = 0;
    read(c);
    read(T);
    if(c<=3){
        while(T--) gtx2::main();
        return 0;
    }
    while(T--) gtx::main();
    return 0;
}
/*
g++ hub.cpp -o hub -std=c++14 "-Wl,--stack=1000000000" -O2;if($?){echo "running";./hub}
*/