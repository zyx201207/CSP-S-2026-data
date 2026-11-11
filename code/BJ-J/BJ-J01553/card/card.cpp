#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200050],c[200050];
bool f[200050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof f);
        vector<int> dec;
        for(int j=i;j<=n;j++) dec.push_back(a[j]);
        vector<int> tab;
        for(int j:dec){
            //cout<<j<<' ';
            for(int k=0;k<tab.size();k++){
                if(tab[k]==j){
                    for(int l=k;l<tab.size();l++) tab.pop_back();
                    break;
                }
            }
            tab.push_back(j);
        }
        //cout<<'\n';
        set<int> x;
        for(int j:tab) x.insert(j);
        //cout<<"\n\n";
        for(int j:x) c[j]++;
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<' ';
    return 0;
}