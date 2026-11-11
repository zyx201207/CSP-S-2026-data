#include<bits/stdc++.h>
using namespace std;
bool b[300000];
int a[500000];
int cnt[300000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    queue<int>q;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++) b[j]=0;
        for(int j=i;j<=n;j++){//插入


            if(b[a[j]]==1){
                while(q.front()!=a[j]){//删除
                    if(q.front()==a[j]) break;
                    b[q.front()]=0;
                    q.pop();


                }

            }
            else q.push(a[j]);
            b[a[j]]=1;
        }
        while(!q.empty()){
            cnt[q.front()]++;

            q.pop();
        }

    }




    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}












