#include<bits/stdc++.h>
using namespace std;
const int MAXN=(int)1e5*5+10;
const int MAXM=(int)1e5*3+10;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> ans(m+10,0);
    for(int T=1;T<=n;T++){
        deque<int> table;
        for(int i=T;i<=n;i++){
            bool find=0;
            int find_;
            for(int k=0;k<table.size();k++){
                if(table[k]==a[i]){
                    find=1;
                    find_=k;
                    break;
                }
            }
            if(find){
                while(table.back()!=a[i]){
                    table.pop_back();
                }
                table.pop_back();
            }
            table.push_back(a[i]);
        }
        for(int i:table){
            ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

/*
4 3
1 2 1 3
*/

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/