#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
stack<int>sta;
int main(void){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        bool book[300005]={0};
        for(int j=i;j<=n;j++){
            if(book[a[j]]){
                while(1){
                    if(sta.top()==a[j])
                        break;
                    book[sta.top()]=0;
                    sta.pop();
                }
            }
            else{
                sta.push(a[j]);
                book[a[j]]=1;
            }
        }
        while(!sta.empty()){
            cnt[sta.top()]++;
            sta.pop();
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",cnt[i]);
    }
    return 0;
}

