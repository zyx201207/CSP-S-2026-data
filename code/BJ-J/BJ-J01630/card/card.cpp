#include<iostream>
#include<stack>



using namespace std;


int n,m;

int f[200010];
int num[200010]={0};
int ans[200010]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    stack<int> k;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    if(n>=1000){
        for(int i=n;i>=1;i--){
            ans[f[i]]=max(ans[f[i]],i);
        }
        for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    }
    int p;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(num[f[j]]==1){
                while(k.top()!=f[j]){
                    num[k.top()]=0;
                    k.pop();
                }
            }
            else{
                k.push(f[j]);
                num[f[j]]=1;
            }
        }
        p=k.size();
        for(int i=1;i<=p;i++){
            num[k.top()]=0;
            ans[k.top()]++;
            k.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
