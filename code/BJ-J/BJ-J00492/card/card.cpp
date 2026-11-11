#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n+1];
    int cnt[200000+10]={0};
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<long long>s;
        int haxi[200000+10];
        memset(haxi,0,sizeof haxi);
        for(int j=i;j<=n;j++){
            if(haxi[a[j]]!=0){
                while(s.top()!=a[j]){
                    haxi[s.top()]=0;
                    s.pop();
                }
            }
            s.push(a[j]);
            haxi[a[j]]=1;
        }
        for(int i=1;i<=m;i++){
            if(haxi[i]==1)cnt[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }



    return 0;
}
