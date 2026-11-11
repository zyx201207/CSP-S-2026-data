#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005]={0};
bool book[300005];
stack<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(book,0,sizeof(book));
        for(int j=i;j<=n;j++){
            if(book[a[j]]==0){
                q.push(a[j]);
                book[a[j]]=1;
            }
            else{
                while(q.top()!=a[j]){
                    book[q.top()]=0;
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            cnt[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
	return 0;
}
