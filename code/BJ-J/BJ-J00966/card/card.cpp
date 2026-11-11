#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],c[N],d[N];
vector <int>b[N];
int main(){
     freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
        b[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        if(b[i].size()>1){
            for(int j=0;j<b[i].size()-1;j++){
       //             cout<<b[i][j]+1<<" "<<b[i][j+1]-1<<" "<<b[a[i]][j]<<endl;
                for(int k=b[i][j]+1;k<=b[i][j+1]-1;k++)c[a[k]]-=b[a[i]][j];
         //       b[a[i]].pop();
            }
        }
    }

    for(int i=1;i<=n;i++){
            d[a[i]]=c[a[i]];
    }
  for(int i=1;i<=m;i++)cout<<d[i]<<" ";
    return 0;
}
