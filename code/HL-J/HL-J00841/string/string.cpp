#include <bits/stdc++.h>
using namespace std;
string v;
int z,n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n*2;i++){
        cin>>v[i];
    }
     for(int i=0;i<n*2;i++){
        if(i%2==0){
            for(int j=0;j<n*2;j+=2){
                if(v[j]!=v[n*2-j]){
                    z+=abs(v[j]-v[n*2-1]);
                }
            }
        }else{
        for(int j=1;j<=n;j+=2){
                if(v[j]!=v[n*2-j]){
                    z+=v[j-1];
                }
        }
     }
     }
     cout<<z;
    return 0;
}
