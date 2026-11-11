#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000+10];
int ans[300000+10];
bool t[300000+10];
stack<int>s;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){


        for(int j=i;j<=n;j++){
            if(t[a[j]]==0){
                t[a[j]]=1;
                s.push(a[j]);
            }

            else{
                t[a[j]]=1;
                while(s.top()!=a[j]){
                    t[s.top()]=0;
                    s.pop();
                }

            }

        }

        while(!s.empty()){
            t[s.top()]=0;
            ans[s.top()]++;
            s.pop();
        }

    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';

    return 0;
}


