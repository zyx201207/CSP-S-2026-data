#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[30][200010],d[30][200010],num[30];
struct node{
    int num,id;
};
vector<node>v[30];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t=a[i],cnt=0;
        while(t){
            b[cnt++][i]=t%2;
            t/=2;
        }
    }
    for(int i=0;i<30;i++){
        for(int j=1;j<=n;j++)
            num[i]+=b[i][j];
    }
    int ans=0,dg=0;
    for(int i=29;i>=0;i--){
        if(num[i]>=m){
            dg=i;
            ans+=int(pow(2,i));
            for(int j=1;j<=n;j++)
                if(b[i][j])
                    v[1].push_back({a[j],j});
            break;
        }
    }
    int cnt=1;
    while(dg){
        memset(num,0,sizeof(num));
        int s=v[cnt].size();
        for(int i=0;i<dg;i++){
            for(int j=0;j<s;j++)
                num[i]+=b[i][v[cnt][j].id];
        }
        bool flg=0;
        for(int i=dg-1;i>=0;i--){
            if(num[i]>=m){
                dg=i;
                ans+=int(pow(2,i));
                for(int j=0;j<s;j++)
                    if(b[i][v[cnt][j].id])
                        v[cnt+1].push_back({v[cnt][j].num,v[cnt][j].id});
                cnt++;flg=1;
                break;
            }
        }
        if(!flg){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
