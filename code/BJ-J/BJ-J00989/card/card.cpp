#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);cout<<3;
    int n,m,a[1000000],b[1000000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
            stack<int> s;
    int x[500005]={};
        for(int j=i;j<=n;j++){
            if(x[a[j]]!=0){
                while(s.top()!=a[j]&&!s.empty()){
                    s.pop();
                }
                s.push(a[j]);
                a[j]=1;

            }else{
                s.push(a[j]);
                b[a[j]]=1;
            }

        }
        while(!s.empty()){
                b[s.top()]++;
                    s.pop();
                }

    }
    for(int i;i<=m;i++){
        cout<<b[i];

    }
    return 0;
}

