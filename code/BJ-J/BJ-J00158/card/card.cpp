#include<iostream>
#include<stack>
using namespace std;
const int N=3000000;
long long n,m,a[N],ans[N];
bool vist[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=N;i++){
        ans[i]=0;
    }
    if(m==2){
            long long ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1&&a[i]==a[n]){
                ans1++;
            }
            else if(a[i]==2&&a[i]==a[n]){
                ans2++;
            }
            else {
                ans1++;
                ans2++;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        stack<long long>q;
        for(int j=1;j<=m;j++){
            vist[j]=false;
        }
        for(int j=i;j<=n;j++){
            if(vist[a[j]]){
                while(!q.empty()&&q.top()!=a[j]){
                    vist[q.top()]=false;
                    q.pop();
                }
            }
            q.push(a[j]);
            if(vist[a[j]])
                q.pop();
            vist[a[j]]=true;
        }
        while(!q.empty()){
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
