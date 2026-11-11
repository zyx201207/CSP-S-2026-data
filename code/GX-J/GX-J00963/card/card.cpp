#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],n,m;
int out[MAXN];
bool vis[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n >>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    stack<int> nums;
    for(int i=1;i<=n;i++){
        for(int i=0;i<=m;i++) vis[i]=0;
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]=1;
                nums.push(a[j]);
            }else{
                while(!nums.empty()&&nums.top()!=a[j]){
                    vis[nums.top()]=0;
                    nums.pop();
                }
            }
        }
        while(!nums.empty()){
            out[nums.top()]++;
            nums.pop();
        }
    }
    for(int i=1;i<=m;i++) cout <<out[i] <<' ';
    return 0;
}
