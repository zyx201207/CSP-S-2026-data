#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s2;
int a[100001],ans[100001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool flag=true;
            while(!s1.empty()){
                if(a[j]==s1.top()){
                    flag=false;
                    break;
                }
                s2.push(s1.top());
                s1.pop();
            }
            if(flag){
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
                s1.push(a[j]);
            }else{
                while(!s2.empty()){
                    s2.pop();
                }
            }
        }
        while(!s1.empty()){
            ans[s1.top()]++;
            s1.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
