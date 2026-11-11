#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,m;
int a[N];
map<int,int> mp;

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<int> b;
        for(int j=i;j<=n;j++){
            bool f=0;
            for(int k=0;k<b.size();k++){
                if(b[k]==a[j]){
                    f=1;
                    break;
                }
            }
            if(f==1){
                bool ff=0;
                int kk=0;
                for(int k=0;k<b.size();k++){
                    if(ff==1){
                        b.erase(b.begin()+kk,b.end());
                        break;
                    }
                    else{
                        if(b[k]==a[j]){
                            kk=k;
                        }
                    }
                }
                b.push_back(a[j]);
            }
            else{
            b.push_back(a[j]);
            }
        }
        for(int j=0;j<b.size();j++)mp[b[j]]++;
    }
    for(int i=0;i<N;i++){
        if(mp[i]!=0) cout<<mp[i]<<" ";
    }
    return 0;
}
