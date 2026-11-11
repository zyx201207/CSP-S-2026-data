#include<bits/stdc++.h>
using namespace std;
long long n, m, ac[500001], ans[300001];
vector<long long> a;
queue<long long> q;
bool clean;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ac[i];
    }
    for(int i=0;i<n;i++){
        while(!q.empty()){
            q.pop();
        }
        while(!a.empty()){
            a.pop_back();
        }
        for(int j=i;j<n;j++){
            q.push(ac[j]);
        }
        for(int j=0;!q.empty();j++){
            long long cur=q.front();
            q.pop();
            a.push_back(cur);
            for(int k=0;k<a.size();k++){
                if(a[k]==cur||clean){
                    clean=true;
                    a.erase(a.begin()+k);
                    k--;
                }
            }
            clean=false;
            a.push_back(cur);
        }
        for(int j=0;j<a.size();j++){
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}