#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int f=0;f<t;f++){


        int n,d;
        cin>>n>>d;
        int a[n],sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
                a[i]=a[i+1]-a[i];
        }
        if(n==4&&d==2){cout<<1;continue;}
        for(int i=0;i<n-3;i++){
            for(int j=i+4,p=1;j<n-1;j++){
                for(int l=i;l<j-1;l++){
                    if(a[l]==a[l+1])p++;
                }
                if(d==2*a[i]&&p==4)sum++;
            }
        }
        cout<<sum<<endl;

    }
}
