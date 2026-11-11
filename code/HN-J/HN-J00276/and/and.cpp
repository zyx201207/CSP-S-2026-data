#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    int j=0;
    cin>>n>>m;
    vector<long long>nrr(n);
    vector<long long>mrr(n/m+5);
    for(int i=0;i<n;i++)
        cin>>nrr[i];
    for(int i=0;i<n;i+=m){
        int k=i;
        for(;k<i+m;k++){
            mrr[j]&=nrr[k];
        }
        j++;
    }
    sort(mrr.begin(),mrr.end(),greater<long long>());
    cout<<mrr[0]<<'\n';

    return 0;
}
