#include<bits/stdc++.h>
using namespace std;
string b[200050];
int f[42][200050];
int g[42][200050];
int a[200050];
int n,m;
int i,j,l;
int ans[63];

string toBit(int x){
    string res="";
    int o=0;
    while(x){
        res=res+char('0'+(x&1));
        o++;
        x=x>>1;
        //cout<<x<<endl;
    }
    l=max(l,o);
    return res;
}

int find(int l,int r){
    int ans=0;
    return ans;
}

void work(int l,int m){//O(6*10^6)
    map <int,int> p;
    int i,j,real_ans=0;
    int io=0;
    for(i=1;i<=l;i++) ans[i]=0;
    for(i=l;i>=1;i--){
        io=0;
        for(j=1;j<=n;j++){
            if(f[i][j]){
                if(!p.count(j)){
                    io++;
                }
            }
        }
        //cout<<io<<endl;
        if(p.size()+io<=m){
            //printf("%d+%d=%d ",p.size(),io,p.size()+io);
            //cout<<i<<endl;
            for(j=1;j<=n;j++){
                if(f[i][j]){
                    p[f[i][j]]=1;
                }
            }
            ans[i]=1;
        }
    }
    real_ans=0;
    for(int _=l;_>=1;_--){
        if(ans[_]){
            real_ans+=1;
        }
        real_ans*=2;
        //cout<<ans[i];
    }
    real_ans/=2;
    cout<<real_ans;
    real_ans=0;
    //out<<endl;
    return ;
}

signed main(){
    //cout<<toBit(65535);
    //return 0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    m=n-m;
    for(i=1;i<=n;i++){
        cin>>a[i];
        b[i]=toBit(a[i]);
    }
    //cout<<l<<endl;
    for(i=1;i<=n;i++){
        for(j=0;j<l;j++){
            if(j>=b[i].size()){
                f[j+1][i]=1;
            }else if(b[i][j]=='1'){
                f[j+1][i]=0;
            }else{
                f[j+1][i]=1;
            }
        }
    }
    /*
    for(i=1;i<=l;i++){
        for(j=1;j<=n;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }


    for(j=1;j<=n;j++){
        cout<<l<<":"<<f[l][j]<<endl;
    }
    */
    work(l,m);
    return 0;
}
