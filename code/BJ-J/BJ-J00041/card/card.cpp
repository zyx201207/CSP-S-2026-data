#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<int> stk;
const int N=5e5+10,M=3e5+10;
bool h[M];
int a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(h,0,sizeof(h));
        for(int j=i;j<=n;j++){
            if(h[a[j]]){
                while(!stk.empty()){
                    if(stk.top()!=a[j]){
                        h[stk.top()]=false;
                        stk.pop();
                    }else break;
                }
            }else{
                h[a[j]]=true;
                stk.push(a[j]);
            }
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
/*
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,bool> ump;
const int N=5e5+10,M=3e5+10;
int a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ump.clear();
        for(int j=i;j<=n;j++){
            if(ump[a[j]]){
                ump.clear();
            }
            ump[a[j]]=true;
        }
        for(auto a:ump){
            ans[a.first]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

*/
