#include<bits/stdc++.h>
using namespace std;
int a[500001],card[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.ans","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<int>f;
            for(int j=i;j<=n;j++){
                bool issp=0;
                for(int k=0;k<f.size();k++)
                    if(a[j]==f[k])
                        issp=1;
                if(issp)
                    while(f.size())
                        f.pop_back();
                else
                    f.push_back(a[j]);}
        for(int k=0;k<f.size();k++)
            card[f[k]]++;

                    while(f.size())
                        f.pop_back();
    }
    for(int i=1;i<=m;i++)
        cout<<card[i]<<' ';
    return 0;
}
