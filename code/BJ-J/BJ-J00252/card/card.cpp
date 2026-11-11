#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
int h[N];
int last[N];

stack<int> temp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++) h[i]=0;

    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(last,0,sizeof(last));
        stack<int> record;

        for(int j=i;j<=n;j++){
            if(a[j]==0) continue;
            int l=last[a[j]];
            if(last[a[j]]){
                for(int k=1;k<record.size()-l-1;k++){
                    temp.push(record.top());
                    record.pop();
                }
                for(int k=l;k<record.size();k++){
                    h[record.top()]=max(0,h[record.top()]-1);
                    last[record.top()]=0;
                    record.pop();
                }
                while(temp.size()){
                    record.push(temp.top());
                    temp.pop();
                }
                record.push(a[j]);
            }
            else{
                last[a[j]]=record.size()+1;
                record.push(a[j]);
                if(j==n){
                    for(int x=1;x<=m;x++){
                        if(last[x]) h[x]++;
                    }
                }
            }
        }

    }
    for(int i=1;i<=m;i++) cout<<h[i]<<' ';
    return 0;
}
