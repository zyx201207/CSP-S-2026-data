#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int f[300005];
int cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){
            f[i]=0;
        }
        stack<int>stk;
        for(int j=i;j<=n;j++){
                int x=0;
                if(f[arr[j]]>0){
                    while(!stk.empty()&&(stk.top()!=arr[j])){
                        f[stk.top()]--;
                        stk.pop();
                    }
                    continue;
                }
            f[arr[j]]++;
            stk.push(arr[j]);
        }
        while(!stk.empty()){
            cnt[stk.top()]++;
            stk.pop();
        }

    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
