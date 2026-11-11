#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    queue <int> q;
    int a[N],num[m+5]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            q.push(a[j]);
            if(q.front()==a[j+1]){
                q.pop();
            }
        }
        while(!q.empty()){
            int t=q.front();
            num[t]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}





