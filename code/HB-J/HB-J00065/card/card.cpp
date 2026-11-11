#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int arr[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> cur;
        for(int j=i;j<=n;j++){
            bool flag=0;
            stack<int> tmp=cur;
            while(!tmp.empty()){
                if(tmp.top()==arr[j]){
                    flag=1;
                    while(cur.top()!=tmp.top()){
                        cur.pop();
                    }
                    break;
                }
                tmp.pop();
            }
            if(!flag){
                cur.push(arr[j]);
            }
        }
        while(!cur.empty()){
            ans[cur.top()]++;
            cur.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
