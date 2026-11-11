#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b,s,z;
    cin>>a>>b;
    long long n[a];
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    while ture{
        z=0
        for(int i=0;i<a-1;i++){
            if(n[i]<n[i+1]){
                s=n[i];
                n[i]=n[i+1];
                n[i+1]=i;
            }
            else{
                z++
            }
        if(z==a-1)
            break;

        }
    }
    cout<<n[b-1];



    return 0;
}
