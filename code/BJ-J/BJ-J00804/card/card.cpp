#include<iostream>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,h;
    long long a[500005];
    long long b[300005];
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        b[i]==0;
    }
    for(int i=n-1;i>=0;i--){
        cin>>h;
        a[i]=h;
    }
    bool e=false;
    while(n--){
        long long c=n;
        for(int i=0;i<n;i++){
            if(e){
                break;
            }
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    c=i;
                    e=true;
                    break;
                }
            }
        }
        for(int i=0;i<=c;i++){
            long long d=a[i];
            b[d-1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]!=0){
            cout<<b[i];
        }
    }
    return 0;
}
