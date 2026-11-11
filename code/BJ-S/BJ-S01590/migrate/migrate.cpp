#include <iostream>
using namespace std;
const int MAXN=2000005;
int c,t,n,l[MAXN],r[MAXN],lst,a,b,mn[MAXN],mx[MAXN];
long long d,x[MAXN],f[MAXN][3],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
            mn[i]=1000000000;
            mx[i]=0;
        }
        l[1]=1;
        for(int i = 2;i <= n;i++){
            l[i]=l[i-1];
            while(x[i]-x[l[i]]>d) l[i]++;
            mn[l[i]]=min(mn[l[i]],i);
            mx[l[i]]=max(mx[l[i]],i);
        }
        r[n]=n;
        for(int i = n-1;i >= 1;i--){
            r[i]=r[i+1];
            while(x[r[i]]-x[i]>d) r[i]--;
        }
        ans=0;
        for(int i = n;i >= 1;i--){
            if(r[i]==i){
                lst=i;
                continue;
            }
            if(r[i]==lst){
                f[i][0]=1;
                f[i][1]=f[i][2]=0;
                continue;
            }
            a=r[i],b=r[a];
            if(l[b]<a-1){
                f[i][0]=1;
                f[i][1]=f[i][2]=0;
            }
            else if(l[b]==a-1){
                f[i][0]=1;
                f[i][1]=0;
                f[i][2]=1+b-mn[a-1];
                if(mx[b] && r[b]!=b) f[i][2]+=min(mx[b],r[b]-1)-mn[b]+1;
                if(l[r[b]]==b) f[i][2]+=f[b][0];
            }
            else{
                f[i][0]=f[a][0]+b-mn[a]+1;
                f[i][1]=f[a][1];
                if(l[b-1]==a) f[i][1]+=f[a][2];
                f[i][2]=0;
                if(mx[a-1] && a-1>i) f[i][2]+=mx[a-1]-mn[a-1]+1;
            }
            ans+=f[i][1]+f[i][2];
        }
        cout << ans << "\n";
    }
    return 0;
}