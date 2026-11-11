#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2000009;
int n,c,t,f,minlen;
ll x[maxn],d,ans;

void s(int st,int ed,int now,int l){
    if(now==ed){
        if(l<minlen){
            minlen=l;
            f=1;
        }
        else if(l==minlen){
            f++;
        }
        return ;
    }
    for(int i=now+1;i<=ed;i++){
        if(x[i]-x[now]<=d){
            s(st,ed,i,l+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            ans=0;
            cin>>n>>d;
            for(int i=1; i<=n; i++){
                cin>>x[i];
            }
            if(d==1){
                cout<<"0\n";
                continue;
            }
            for(int i=1;i<=n;i++){//u
                if(x[i]-x[1]+d>n-d+1){
                    break;
                }
                for(int j=i+3;j<=n;j++){//v
                    f=0,minlen=5009;
                    s(i,j,i,0);
                    //printf("from%dto%d,minlen=%d,f=%d\n",i,j,minlen,f);
                    if(f==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
