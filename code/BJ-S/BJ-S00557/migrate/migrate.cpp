#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10,M=2e6+10,INF=1e18;
int c,t,cnt=0;
int n,a[M],d,mdist[N][N];
pair<int,int> p[N][N];
void tfo(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<"{"<<p[i][j].first<<","<<p[i][j].second<<"}"<<' ';
        }
        cout<<'\n';
    }
}
void solve1(){
    cin>>n>>d;
    cnt=0;
    memset(mdist,0,sizeof mdist);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            p[i][j]={INF,0};
        }
        cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return ;
    }
    for(int i=1;i<=n;i++){
        p[i][i]={0,1};
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]>d){
                mdist[1][i]=(j-1);
                break;
            }else{
                p[i][j]={1,1};
            }
        }
    }
    for(int q=2;q<=n;q++){
        for(int i=1;i<=n;i++){
            for(int j=mdist[q-1][i]+1;j<=n;j++){
                int minn=INF,tms=0;
                for(int k=i+1;k<j;k++){
                    if(k>mdist[q-1][i]||j>mdist[q-1][k]){
                        continue;
                    }else if(minn==p[i][k].first+p[k][j].first){
                        tms++;
                    }else if(minn>p[i][k].first+p[k][j].first){
                        minn=p[i][k].first+p[k][j].first;
                        tms=1;
                    }
                    mdist[p[i][k].first+p[k][j].first][i]=max(mdist[p[i][k].first+p[k][j].first][i],j);
                }
                if(minn==INF){
                    break;
                }else{
                    if(p[i][j].first>minn){
                        p[i][j].first=minn;
                        p[i][j].second=tms;
                    }else if(p[i][j].first==minn){
                        p[i][j].second=tms;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(p[i][j].second==2){
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    tfo();
}
void solve2(){
    cnt=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return ;
    }
    int diff=a[2]-a[1];
    if(d<=diff){
        cout<<0<<'\n';
        return ;
    }
    int st=d/diff;
    for(int i=1;i<=n;i++){
        if(i+2*st-1<=n){
            cnt++;
        }else{
            break;
        }
    }
    cout<<cnt<<'\n';
}
void solve3(){
    cnt=0;
    cin>>n>>d;
    int mid;
    bool fl1,fl2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return ;
    }
    for(int i=1;i<=n;i++){
        if(abs(a[i]-a[1])<=d&&abs(a[i]=a[n])<=d){
            mid=i;
            break;
        }
    }
    if(abs(a[mid+1]-a[1])<=d){
        fl1=1;
    }
    if(abs(a[mid-1]-a[n])<=d){
        fl2=1;
    }
    if(fl1&&fl2){
        cout<<0<<'\n';
        return ;
    }else if(fl2){
        for(int i=mid-1;i<=n;i++){
            if(abs(a[mid-1]-a[i])<=d&&abs(a[mid-2]-a[i])>d){
                cnt++;
            }else if(abs(a[mid-1]-a[i])>d){
                break;
            }
        }
        cout<<cnt<<'\n';
    }else if(fl1){
        for(int i=mid+1;i>=1;i--){
            if(abs(a[mid+1]-a[i])<=d&&abs(a[mid+2]-a[i])>d){
                cnt++;
            }else if(abs(a[mid+1]-a[i])>d){
                break;
            }
        }
        cout<<cnt<<'\n';
    }else{
        cout<<0<<'\n';
        return ;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(c==11||c==12){
            solve2();
        }else if(c==13||c==14){
            solve3();
        }else{
            solve1();
        }
        
    }
    return 0;
}
