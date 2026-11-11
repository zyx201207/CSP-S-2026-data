#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> fs(n);
    vector<vector<int>> pdb(31);
    for(auto &x:fs){
        cin>>x;
        for(int i=x;i!=0;i=i&(i-1)){
            pdb[__builtin_ctz(i)].push_back(x);
        }
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int x=i,sum=0,cnt=pdb[i].size();
        queue<int> now,_;
        for(auto &x:pdb[i]) now.push(x);
        _=now;
        while(cnt>=m){
            sum+=1<<x;
            cnt=0;
            for(int j=x-1;j>=0;j--){
                int c=0;
                queue<int> ne;
                while(_.size()){
                    if((_.front()&(1<<j))!=0){
                        c++;
                        ne.push(_.front());
                    }
                    _.pop();
                }
                if(c>=m){
                    cnt=c;
                    x=j;
                    now=ne;
                    _=now;
                    break;
                }
                _=now;
            }
        }
        if(pdb[i].size()>=m){
            ans=sum;
            break;
        }
    }
    cout<<ans;
    return 0;
}
//pdboynbkls
