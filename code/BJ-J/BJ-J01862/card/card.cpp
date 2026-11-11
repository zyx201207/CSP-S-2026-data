#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
bool tp=1;
vector<long long >cd;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1 and a[i]<a[i-1])tp=0;
    }
    if(!tp){
    for(int js=1;js<=n;js++){
        for(int i=js;i<=n;i++){
            for(int j=0;j<cd.size();j++){
                if(a[i]==cd[j]){while(cd[cd.size()-1]!=a[i])cd.erase(cd.end()-1);
                cd.erase(cd.end()-1);break;}
            }
            cd.push_back(a[i]);
        }
        for(int i=0;i<cd.size();i++){
            ans[cd[i]]++;
        }
        cd.clear();
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";}
    else{
        for(int i=1;i<=n;i++){
            if(i==n or a[i+1]!=a[i]){
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";

    }
    return 0;
}