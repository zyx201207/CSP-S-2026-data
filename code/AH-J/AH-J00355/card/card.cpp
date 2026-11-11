#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int t[N];
queue<int> pai;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int tg=1;tg<=n;tg++){
        for(int i=tg;i<=n;i++){
            int k=a[i];
            if(pai.empty()){
                pai.push(a[i]);
            }
            else{
                int top0=pai.front();
                if(top0==k){
                    while(!pai.empty()){
                        pai.pop();
                    }
                }else{
                    bool f=1;
                    while(1){
                        int top1=pai.front();
                        pai.pop();
                        if(top1==k)f=0;
                        if(f==1){
                            pai.push(top1);
                        }
                        if(pai.front()==top0){
                            break;
                        }
                    }
                }
                pai.push(k);
            }
        }
        while(!pai.empty()){
            int top1=pai.front();
            pai.pop();
            t[top1]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
