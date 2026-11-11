#include<bit/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,z=0;
    int num;
    cin>>n,m>>endl;
    cin>>num;
    sort(sum);
    if(m==0){
        for i in range(sum){
            if(sum[i]==sum[i+1]){
                z++;
            }       
        }
    for j in range(sum){
        if(sum[j]+1==sum[J+1]){
            m--;
            z++;
            if(m==0){
                break;    
            }
        }
    }
    cout<<z;
    retern 0;
    
}