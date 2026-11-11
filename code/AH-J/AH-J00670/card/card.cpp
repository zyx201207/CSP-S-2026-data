#include<iostream>
#include<vector>
#define int long long
using namespace std;
int n,m,a[500005];
vector<int> g;
int tong[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n*n*m<=100000000){
        for(int start=1;start<=n;start++){
            while(g.size()>0)   g.pop_back();
            for(int i=start;i<=n;i++){
                int p;
                bool f=0;
                for(int k=0;k<g.size();k++){
                    int j=g[k];
                    if(a[i]==j){
                        p=k;
                        f=1;
                        break;
                    }
                }
                if(f){
                    for(int j=(int)(g.size())-1;j>p;j--){
                        g.pop_back();
                    }
                }else{
                    g.push_back(a[i]);
                }
            }
            for(int i : g){
                tong[i]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<tong[i]<<' ';
        }
    }else{
        for(int start=1;start<=n;start++){
            while(g.size()>0)   g.pop_back();
            for(int i=start;i<=n;i++){
                int p;
                bool f=0;
                if(g.size()==0||a[i]!=g[(int)(g.size()-1)]){
                    g.push_back(a[i]);
                }
            }
            for(int i : g){
                tong[i]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<tong[i]<<' ';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
