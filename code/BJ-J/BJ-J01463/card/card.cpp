#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans,b,cnt,mp[300010];
vector<int> v[3010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];v[a[i]].push_back(i);}
    for(int j=1;j<=n;j++){
        int i=j;
        if(i==n)mp[a[n]]++;
        while(i<n){
            if(v[a[i]].size()-1<cnt+1){
                mp[a[i]]++;
                i++;
            }else{
                int r=v[a[i]].size();
                i=v[a[i]][r-1];
                mp[a[i]]++;
                for(int k=v[a[i+1]].size()-1;k>=0;k--){
                    if(v[a[i+1]][k]==i+1){
                        cnt=k;
                        break;
                    }
                }
                if(i+1==n)mp[a[i+1]]++;
                i++;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
    return 0;
}
