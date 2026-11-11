#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define Pi pair<int,int>
#define Mp(a,b) make_pair(a,b)
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> crystal(n),st(n);
    priority_queue<Pi,vector<Pi>,greater<Pi> > barrier;
    for(auto &i:crystal)cin >> i;
    sort(crystal.begin(),crystal.end());
    for(int i=1;i<n;i++){
        st[i]=crystal[i]-crystal[i-1];
        barrier.push(make_pair(st[i],i));
    }
    int rop=m,ans=0;
    while(rop>0){
        Pi nearest=barrier.top();
        barrier.pop();
        if(nearest.first>rop||nearest.first==0)break;
        rop-=nearest.first;
        st[nearest.second]-=nearest.first;
        ans++;
    }
    cout << ans;
    return 0;
}
/*
2 2 4 8 9
  0 2 4 1
  0 1 2 4
  1 4 2 3

*/