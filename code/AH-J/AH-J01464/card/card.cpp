#include<bits/stdc++.h>

using namespace std;
int a[500005];
map<int,int> mp;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> t;
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 1;i<=m;i++) mp[i] = 0;
    for(int i = 0;i<n-1;i++){
        t.clear();
        for(int j = i;j<n;j++){
            if(binary_search(t.begin(),t.end(),a[j])){
                auto ita = lower_bound(t.begin(),t.end(),a[j]);
                auto itb = upper_bound(t.begin(),t.end(),a[j]);
                itb++;
                t.erase(ita,itb);
            }
            t.push_back(a[j]);
            //cout<<"table:";
            //for(int i = 0;i<t.size();i++) cout<<t[i]<<' ';
            //cout<<endl;
        }
        for(int i = 0;i<t.size();i++){
            mp[t[i]]++;
        }
        //cout<<endl;
    }
    mp[a[n-1]]++;
    for(int i = 1;i<=m;i++) cout<<mp[i]<<' ';
    return 0;
}
/*

*/
//CCF please let me AC!
