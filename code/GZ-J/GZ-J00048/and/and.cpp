//GZ-J00048  赵晨希   贵阳市白云区第十四中学
#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long b[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=n-m;i--){
        while(a[i]/2!=0){
                b[i]=a[i]%2;
                a[i]/=2;

        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]==1){
            for(int l=n-i;l>=0;l--){
                sum+=2;
            }
        }
    }

    cout<<sum;



    return 0;
}

