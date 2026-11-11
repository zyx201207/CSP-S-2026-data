#include<bits/stdc++.h>
using namespace std;
int n,m,m1[300005],n1[500005];
deque<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&n1[i]);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(find(q.begin(),q.end(),n1[j])!=q.end()){
                int t=q.back();
                while(t!=n1[j]){
                    q.pop_back();
                    t=q.back();
                }
            }
            else
                q.push_back(n1[j]);
        }
        while(!q.empty()){
            int t=q.front();
            m1[t]++;
            q.pop_front();
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",m1[i]);
    return 0;
}