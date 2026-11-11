#include<bits/stdc++.h>
using namespace std;
int n,m,flag[1000010],a[1000010],summ[1000010];
queue<int> s;
int main(){
    freopen("card","r","in");
    freopen("card","w","out");
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int o=1;o<=m;o++){
           flag[o]=0;
        }
        for(int j=i;j<=n;j++){
            s.push(a[j]);
            flag[a[j]]+=1;
            if(flag[a[j]]==2){
                s.pop();
                while(s.front()!=a[j]){
                    flag[s.front()]--;
                    s.pop();
                }
                flag[a[j]]=1;
            }
        }
        while(!s.empty()){
            s.pop();
        }
        for(int j=1;j<=m;j++){
            summ[j]+=flag[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<summ[i]<<" ";
    }
    return 0;
}
