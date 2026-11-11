#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>v;
vector<int>ans;
int huge=2e5+10;
void BFS(int index,int cnt){
    if(cnt==m){
        int cvb=v[0];
        for(int i=1;i<m;i++){
            cvb=cvb & v[i];
        }
        if(cvb<huge)huge=cvb;
        retrun;
    }
    ans.push_back(v[index]);
    BFS(index+1,cnt+1);
    ans.pop_back();
    BFS(index+1,cnt);

}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    BFS(0,0);
    cout<<huge;
    return 0;
}
