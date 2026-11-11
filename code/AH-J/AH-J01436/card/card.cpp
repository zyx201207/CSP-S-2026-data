#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        stack<int>s;unordered_map<int,int>ma;
        for(int j=0;j<i;j++)s.push(a[j]),ma[a[j]]++;
        for(int j=i+1;j<n;j++){
            if(ma[a[j]])
                while(s.top()!=a[j])ma[s.top()]--,s.pop();
            if(s.size()&&s.top()==a[j])s.pop(),ma[a[j]]--;
            s.push(a[j]);
        }while(s.size())b[s.top()]++,s.pop();
    }for(auto&i:b)cout<<i<<' ';
    return 0;
}
