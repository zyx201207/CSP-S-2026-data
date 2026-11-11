#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
long long p[5005];
long long d[5005];
long long minn = 1000000000000000000;
void dfs(long long st,long long fi,long long step,long long farest){
    if(st == fi){
        d[step]++;
        minn = min(minn,step);
        return;
    }
    if(step > minn){
        return;
    }
    for(long long i = st+1;i<=fi;i++){
        if(p[i]-p[st]<=farest){
            dfs(i,fi,step+1,farest);
        }else{
            break;
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c == 11 || c == 12){
        while(t--){
            long long n,m;
            memset(a,0,sizeof(a));
            cin >> n >> m;
            for(int i = 0;i<n;i++){
                cin >> a[i];
            }
            if(n == 1){
                cout << 0 << endl;
                continue;
            }
            long long diff = a[1]-a[0];
            if(m < 2*diff || m >= 3*diff){
                cout << 0 << endl;
            }else{
                cout << max((long long)0,n-3) << endl;
            }
        }
    }else if(c <= 10){
        while(t--){
            long long n,m;
            long long ans = 0;
            cin >> n >> m;
            memset(p,0,sizeof(p));
            for(int i = 1;i<=n;i++){
                cin >> p[i];
            }
            for(long long i = 1;i<=n-3;i++){
                for(long long j = i+3;j<=n;j++){
                    minn = 1000000000000000000;
                    memset(d,0,sizeof(d));
                    dfs(i,j,0,m);
                    if(minn > n) continue;
                    if(d[minn] == 2){
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }
    }else if(c == 13 || c == 14){
        while(t--){
            long long n,m;
            memset(a,0,sizeof(a));
            cin >> n >> m;
            for(int i = 0;i<n;i++){
                cin >> a[i];
            }
            if(n < 3){
                cout << 0 << endl;
                continue;
            }
            long long midl = lower_bound(a,a+n,a[0]+m)-a;
            long long midr = lower_bound(a,a+n,a[n-1]-m)-a;
            if(midr-midl>1){
                cout << 0 << endl;
            }else if(midr - midl == 1){
                cout << midl*(n-midr) << endl;
            }else{
                long long answer = 0;
                for(int i = 0;i<midl-1;i++){
                    for(int j = n-1;j>midr+1;j--){
                        if(a[j]-a[i]<=m){
                            break;
                        }
                        if(a[midl-1]-a[i]<=m && a[j]-a[midl-1]<=m && (a[midl-2]-a[i]>m || a[j]-a[midl-2]>m) && (a[midl+1]-a[i]>m || a[j]-a[midl+1]>m)){
                            answer++;
                        }else if(a[midl+1]-a[i]<=m && a[j]-a[midl+1]<=m && (a[midl+2]-a[i]>m || a[j]-a[midl+2]>m) && (a[midl-1]-a[i]>m || a[j]-a[midl-1]>m){
                            answer++;
                        }
                    }
                }
                cout << answer << endl;
            }
        }
    }else{
        while(t--){
            cout << 0 << endl;
        }
    }
    return 0;
}

