#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
vector<int> v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> v;
        for(int j=i;j<=n;j++){
            int flag=-1;
            for(int s=0;s<v.size();s++){
                if(v[s]==a[j]){
                    flag=s;
                }
            }
            if(flag!=-1){
                v.erase(v.begin()+flag+1,v.end());

            }else{
                v.push_back(a[j]);
            }
        }
        for(int p=0;p<v.size();p++){
            t[v[p]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
