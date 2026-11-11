#include <bits/stdc++.h>
using namespace std;
int b[1000010];
int c[1000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a;
    deque<int>q;
    cin>>n>>m;
    for(int j=1;j<=n;j++)
            {
                cin>>a;
                q.push_front(a);
            }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                c[j]=0;

            for(int j=1;j<=n;j++){
                if(c[q[j]]==0)
                    c[q[j]]=j;
                else{
                    for(int k=c[q[i]];k<=j;k++){
                            c[q[k]]=0;
                    }
                }
            }
            for(int j=1;j<=m;j++){
                if(c[b[j]]!=0)
                    b[j]++;
            }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
}
