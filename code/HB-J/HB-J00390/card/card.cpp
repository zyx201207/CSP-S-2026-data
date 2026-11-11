#include<bits/stdc++.h>
using namespace std;
vector<int>l;
int m,n;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int x[n+1];
    for (int i=0;i<n;i++){
        cin>>x[i];
    }
    int ans[m+1]={0};
    for (int i=0;i<n; i++){
        for (int j=0;j<n-i; j++){
            for (int k=0;k<l.size(); k++){
                if(l[k]==x[j]){
                    for (int s=l.size();s>k;s--){
                        l.pop_back();
                    }
                    continue;
                }
            }
        l.push_back(x[j]);
        }
        for (int j=1;j<=l.size();j++){
            ans[l[j]]++;
        }
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
}