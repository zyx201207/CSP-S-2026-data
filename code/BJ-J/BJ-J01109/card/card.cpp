#include<bits/stdc++.h>
using namespace std;
long long n,m,z,a[500010],b[300010];
std::stack<long long> e;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(long long j=m-i;j<=n;j++){
            if(e.emplace(j)=0){
                e.push(j);
            }
            else{
                while(1!=2){
                    if(e.top()==j){
                        e.pop();
                        break;
                    }
                    e.pop();
                }
            }
        }
        for(long long j=1;j<=m;j++){
            if(e.swap(j)!=0){
                b[j]++;
            }
        }
        e.empty();
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
