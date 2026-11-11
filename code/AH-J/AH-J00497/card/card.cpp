#include<bits/stdc++.h>
using namespace std;
struct card{
    bool f;
    int s;
};card x[300007];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int n,m,c[300007],vis[300007]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    string s="";
    int t=n;
    while(t){
        for(int i=0;i<n;i++){
            if(x[c[i]].f==0){
                s.push_back(c[i]+'0');
                x[c[i]].f=1;
                x[c[i]].s=i;
            }else{
                s.erase(x[c[i]].s,(i-x[c[i]].s));
                for(int j=x[c[i]].s;j<i;j++){
                    x[i].f=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            vis[s[i]-'0']++;
        }
        t--;
    }
    for(int i=1;i<=m;i++){
        cout<<vis[i]<<" ";
    }
    return 0;
}
