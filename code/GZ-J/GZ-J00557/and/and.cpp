//GZ-J00557 贵阳市南明区第一实验中学 夏泽轩
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m;
vector<vector<int>>t(31);
vector<int>c;
vector<int>backtrack(vector<int>&v,int z){
    if(v.size()==m)
        return v;
    vector<int>n_v;
    for(int&i:v)
        if(i>>(c[z]-1)%2==1)
            n_v.push_back(i);
    if(n_v.size()<=m)
        return backtrack(v,z+1);
    return backtrack(n_v,z+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int>num(n);
    for(int&i:num){
        cin>>i;
        int k=i;
        for(int j=0;j<=30;j++){
            if(k%2==1){
                t[j].push_back(i);
                if(t[j].size()==m)
                    c.push_back(j);
            }
            k>>=1;
            if(k==0)
                break;
        }
    }
    if(c.size()==0){
        cout<<'0';
        return 0;
    }
    sort(c.begin(),c.end(),cmp);
    vector<int>v=backtrack(t[c[0]],1);
    int u=v[0];
    for(int&i:v)
        u&=i;
    cout<<u;
    return 0;
}
