#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
long long n,m;
long long a[N];
long long in[M];
long long ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    stack<int> s;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(in[a[j]]==0){
                s.push(a[j]);
                in[a[j]]++;
            }
            else{
                bool flag=false;
                while(!s.empty()){
                    if(flag==false&&s.top()!=a[j]){
                        in[s.top()]--;
                        s.pop();
                    }
                    else if(flag==false&&s.top()==a[j]){
                        flag=true;
                        in[s.top()]--;
                        s.pop();
                    }
                    else if(flag==true&&s.top()==a[j]){
                        in[s.top()]--;
                        s.pop();
                    }
                    else if(flag==true&&s.top()!=a[j]){
                        break;
                    }
                }
                s.push(a[j]);
                in[a[j]]++;
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
        for(long long j=1;j<=m;j++){
            in[j]=0;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
