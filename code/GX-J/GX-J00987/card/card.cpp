#include<bits/stdc++.h>
using namespace std;
struct Ds{
    int k;
};
Ds ds[300005];
int a[300005];
int ans[300005];
int main(){
    int n,m;
    cin>>n>>m;
    stack<int> s;
    int sum1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ds[i].k=a[i];

    }
    s.push(a[1]);
    for(int i=1;i<=n;i++){
          for(int j=i;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    if(ds[j].k==a[z]){
                s.push(ds[j].k);
                sum1=z;
                while(sum1>z){
                    s.pop();
                }

                ans[ds[j].k]+=1;
            }
                }


          }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[ds[j].k]!=0){
                cout<<ans[ds[j].k];
            }
        }
    }
    return 0;
}
