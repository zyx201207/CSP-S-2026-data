#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
pair<bool,int> t[300005];
int cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[j].first=false;
            t[j].second=0;
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]].first){
                for(int k=1;k<=m;k++){
                    if(t[k].first&&t[k].second>t[a[j]].second){
                        t[k].second=0;
                        t[k].first=false;
                    }
                }
            }
            else{
                t[a[j]].first=true;
                t[a[j]].second=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(t[j].first){
                cnt[j]++;
            }
            //cout<<cnt[j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
