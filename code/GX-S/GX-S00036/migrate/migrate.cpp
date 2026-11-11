#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2*(int)1e6+5];
int q=0;
struct node{int l;int r;};
vector <vector <node>> pa;
int k,d;
void dfs(int l,int r){//cout<<"apobj";
    if (k>2) return;
    //cout<<l<<'>'<<r<<endl;
    if (l==r){
        k++;
        q++;
        //cout<<"ad"<<pa[pa.size()-1].size()<<"ad";
        //for (int i=0;i<pa[pa.size()-1].size();i++) cout<<k<<':'<<pa[pa.size()-1][i].l<<'>'<<pa[pa.size()-1][i].r<<' ';cout<<endl;
        //pa.push_back(vector <node>());cout<<'j'<<endl;
        return;
    }
    for (int i=l+1;i<=r;i++){
        if (a[i]-a[l]<=d){
            //cout<<"shi"<<i<<'>'<<r<<endl;
            //pa[pa.size()-1].push_back({l,i});
            dfs(i,r);
            //pa[pa.size()-1].pop_back();
        }else break;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n;
        cin>>n>>d;
        for (int i=0;i<n;i++) cin>>a[i];
        //pa.clear();
        //pa.push_back(vector <node>());
        q=0;
        k=0;
        int ans=0;
        for (int l=0;l<n;l++){
            for (int r=l+2;r<n;r++){
                dfs(l,r);//cout<<k<<endl;
                if (k==2) ans++;
                k=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
