#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int nums[500050];
void solve(int i){
    stack<int> s;
    bool num[500050]={0};
    for(int j=i;j<=n;j++){
        if(num[a[j]]){
            while(s.top()!=a[j]){
                nums[s.top()]--;
                num[s.top()]=0;
                s.pop();
            }
        }else{
            s.push(a[j]);
            nums[a[j]]++;
            num[s.top()]=1;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++){
        cout<<nums[i]<<' ';
    }
    return 0;
}
