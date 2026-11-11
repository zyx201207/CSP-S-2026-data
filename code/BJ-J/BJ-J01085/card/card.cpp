#include<bits/stdc++.h>
using namespace std;
int a[500001],cnt[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    queue<int> q;
    cin >> n >> m;
    int d=n-1;
    for(int k=1;k<=n;k++){
        cin >> a[k];
    }
    for(int s=1;s<=n;s++){
        int i=n-d;
        for(i;i<=n;i++){
            int f=a[i],pop=-1;
            for(int j=i+1;j<=n;j++) if(a[j]==f) pop=j;
            if(pop!=-1){
                i=pop;
                q.push(a[pop]);
            }
            else{
                q.push(a[i]);
            }
        }
        for(int k=1;k<=q.size();k++){
            cnt[q.front()]++;
            q.pop();
        }
        d--;
    }
    cnt[a[n]]=n;
    for(int i=1;i<=m;i++) cout << cnt[i] << " ";
    return 0;
}
