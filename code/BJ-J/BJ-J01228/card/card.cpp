#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
stack<int> b;
bool cx[500005];
bool v[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            long long t=a[j];
            //cout<<i<<" "<<t<<" "<<cx[t]<<" "<<endl;
            if(cx[t]){
                while(b.top()!=t&&!b.empty()){
                    v[b.top()]=0;
                    cx[b.top()]=0;
                    b.pop();
                }
            }
            else b.push(t);v[t]=1;cx[t]=1;
        }
        //cout<<"v:"<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
        for(int k=1;k<=m;k++){
            if(v[k]) sum[k]+=1;
        }
        for(int i=1;i<=5001;i++){
            cx[i]=0;
            v[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
