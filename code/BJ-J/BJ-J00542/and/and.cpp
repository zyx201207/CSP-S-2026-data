#include<bits/stdc++.h>
using namespace std;

int n,m,maxn,num[200005],tmp=0;
vector<int> a[40];
bool numb[200005][40];
void f(int x,int y){
    bool b[40];
    int cnt=0;
    while(x>0){
        cnt++;
        b[cnt]=x%2;
        x/=2;
    }
    maxn=max(cnt,maxn);
    for(int i=cnt;i>0;i--){
        if(b[i]){
            a[i].push_back(y);
            a[i][0]++;
            numb[y][i]=1;
        }
    }
    return;
}
void F(int t){
    for(int i=t-1;i>0;i--){
        int cnt=0;
        for(int j=1;j<=a[t][0];j++) if(numb[a[t][j]][i]) cnt++;
        if(i==1&&cnt<m){
            cout<<tmp;
            return;
        }
        if(cnt==m){
            int ans=num[a[i][1]];
            for(int k=2;k<=cnt;k++) ans=ans&num[a[t][k]];
            cout<<ans;
            return;
        }
        else if(cnt>m){
            tmp=tmp+pow(2,i-1);
            F(i);
            return;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=30;i++) a[i].push_back(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        num[i]=x;
        f(x,i);
    }
    for(int i=maxn;i>0;i--){
        if(i==1&&a[i][0]<m){
            cout<<0;
            return 0;
        }
        if(a[i][0]==m){
            int ans=num[a[i][1]];
            for(int j=2;j<=a[i][0];j++) ans=ans&num[a[i][j]];
            cout<<ans;
            return 0;
        }
        else if(a[i][0]>m){
            tmp+=pow(2,i-1);
            F(i);
            return 0;
        }
    }
    return 0;
}
