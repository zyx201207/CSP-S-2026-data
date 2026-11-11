#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[50005];
queue<int> q;
vector<int> c;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            q.push(a[i]);
        }while (!q.empty()){
            int x=q.front();
            q.pop();
            int d=c.size();
            for (int k=0;k<d;k++){
                if (c[i]==x){
                    for (int l=k;l<d;l++)c.pop_back();
                    break;
                }
            }
            c.push_back(x);
        }
        for (int j=0;j<c.size();j++)a[c[j]]++;
    }
    for (int i=1;i<=m;i++)cout<<a[i]<<" ";
    return 0;
}
