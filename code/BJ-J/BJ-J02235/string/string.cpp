#include<bits/stdc++.h>
using namespace std;
int const N=1000000000;
char a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,o=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char s;
        cin>>x>>s;
        for(int j=1;j<=x;j++){
            a[o+j]=s;
        }
        o=o+x;
    }
    long long sum=0;
    for(int i=1;i<=o/2+1;i++){
            if(i==o-i+1 || i+1==o-i+1){
                    if(a[i]!=a[o-i+1]){
                        sum+=1;
                    }
                break;
            }
            if(a[i]!=a[o-i+1]){
                sum+=1;
            }
    }
    cout<<sum;
return 0;
}
