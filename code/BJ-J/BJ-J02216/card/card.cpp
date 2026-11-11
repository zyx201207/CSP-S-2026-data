#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int n,m,a[500005],c[300005];
bool visit[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        memset(visit,0,sizeof(visit));
        stack<int>s;
        for(int j=i;j<n;j++){
            if(!visit[a[j]]){
                s.push(a[j]);
                c[a[j]]++;
                visit[a[j]]=true;
            }else{
                while(s.top()!=a[j]){
                    c[s.top()]--;
                    visit[s.top()]=0;
                    s.pop();
                }
            }
        }
    }for(int i=1;i<=m;i++)cout<<c[i]<<' ';
    return 0;
}
