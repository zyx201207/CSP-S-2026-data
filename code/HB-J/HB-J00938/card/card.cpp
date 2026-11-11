#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,maxm=3e5+10;
int n,m,a[maxn],ans[maxm];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> t;
        for(int j=i;j<=n;j++){
            int card=a[j],pos;
            bool f=false;
            for(int k=0;k<t.size();k++){
                if(t[k]==card){
                    f=true;
                    pos=k;
                }
            }
            if(f){
                int sum=t.size()-pos-1;
                for(int k=1;k<=sum;k++){
                    t.pop_back();
                }
            }else{
                t.push_back(card);
            }
        }
        for(int j=1;j<=m;j++){
            bool f=false;
            for(int k=0;k<t.size();k++){
                if(t[k]==j){
                    f=true;
                }
            }
            if(f){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
