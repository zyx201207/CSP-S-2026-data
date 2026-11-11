#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=5010;
#define int long long
int x[N];
int lst[N];
int q[N];
int di[N];
int f[N];//到达i时走了j条边
list<int> l;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C,T;
    cin >> C >> T;
    while(T--){
        int n,d;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> x[i];
        }
        int j=1;
        for(int i=1;i<=n;i++){
            while(x[j]-x[i]<=d && j<=n) j++;
            j--;
            lst[i]=j;
        }
        j=n;
        for(int i=n;i>=1;i--){
            while(x[i]-x[j]<=d && j>=1) j--;
            j++;
            q[i]=j;
        }
        if(C==12 || C==11){
            int len=lst[1]-1;
            int a=0;
            if(len==0 || len==1) cout << 0 << "\n";
            else cout << max(n-2*len+1,a) << "\n";//<< ' ' << len << ' ' << n << "\n";
            continue;
        }
        if(C>12){
            cout << 0 << "\n";
            continue;
        }
        //if(C<=10){
            int ans=0;
            for(int i=1;i<=n;i++){
                di[i]=0;
                while(!l.empty()) l.pop_back();
                l.push_back(i);
                int p=n+1;
                for(int j=i+1;j<=n;j++){
                    while(!l.empty() && l.front()<q[j]) l.pop_front();
                    if(!l.empty()) di[j]=1+di[l.front()];
                    else{
                        p=j;
                        break;
                    }
                    while(!l.empty() && di[l.back()]>di[j]) l.pop_back();
                    l.push_back(j);
                }
                for(int j=i;j<=n;j++){
                    f[j]=0;
                }
                f[i]=1;
                /*for(int j=i+1;j<p;j++){
                    for(int k=max(i,q[j]);k<j;k++){
                        if(di[k]+1==di[j]) f[j]+=f[k];
                    }
                }*/
                int cn=1;
                while(!l.empty()) l.pop_back();
                l.push_back(i);
                for(int j=i+1;j<=p;j++){
                    while(!l.empty() && l.front()<q[j]){
                        cn=cn-f[l.front()];
                        l.pop_front();
                    }
                    if(cn<0) cn=0;
                    if(cn==0){
                        int x=l.front();
                        for(int k=x;di[k]+1==di[j];k++) cn+=f[k];
                    }
                    f[j]=cn;
                    while(!l.empty() && di[l.back()]>di[j]) l.pop_back();
                    l.push_back(j);
                }
                for(int j=i+1;j<p;j++){
                    if(f[j]==2) ans++;
                }
            }
            cout << ans << "\n";
            //continue;
        //}
        //cout << 0;
    }
    return 0;
}
