#include<bits/stdc++.h>
using namespace std;
int a[100005],b1[100005]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        queue<int>q;
        int b[100005]={};
        for(int j=i;j<=n;j++){
            if(b[a[j]]>=1){
                while(q.empty()==0) q.pop();
                for(int l=1;l<=m;l++)   b[l]=0;
            }
            q.push(a[j]);
            b[a[j]]++;
        }
        int p=q.size();
        for(int j=1;j<=p;j++){
            b1[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b1[i]<<' ';
    }
    return 0;
}
