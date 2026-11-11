#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    string a,b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int h;
        while(a[i]%2==0){
            h=a[i]%2;
            a[i]/=10;
            b[i]=h;
            h=0;
        }
    }
    for(int i=2;i<=n;i++){
        int y=b[i-1]^b[i];
        if(y>sum){
            sum=y;
            y=0;
        }
    }
    cout<<sum;
    return 0;
}
