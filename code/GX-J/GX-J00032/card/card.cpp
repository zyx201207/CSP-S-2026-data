#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],b[300005]={},cnt[300005];
    stack<int>q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]==0){
                q.push(a[j]);
                cnt[a[j]]++;
            }else{
                while(q.top()!=a[j]){
                    cnt[q.top()]--;
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            b[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
	return 0;
}
