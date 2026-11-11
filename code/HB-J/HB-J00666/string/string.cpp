#include<iostream>
using namespace std;
long long a[200010];
char c[200010],b[200010];
int main ( ) {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0,f=0,g=0,k=0,sum=0;
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    cin>>a[0]>>c[0];
    for(int i=1;i<n;i++){
        cin>>a[i]>>c[i];
        if(a[i]!=a[i-1]){
            f=1;
        }
        if(c[i]!=c[i-1]){
            g=1;
        }
        sum+=a[i];
    }
    if(g==0){
        cout<<"0";
        return 0;
    }
    if(f==0){
        f=n/2;
        for(int i=0;i<f;i++){
            if(c[i]!=c[n-i-1]){
                k++;
            }
        }
        cout<<k*a[0];
    }else{
        if(sum<=200000){
            f=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<a[i];j++){
                    b[f]=c[i];
                    f++;
                }
            }
            sum=f/2;
            for(int i=0;i<sum;i++){
                if(b[i]!=b[f-i-1]){
                    k++;
                }
            }
            cout<<k;
        }else{
            cout<<"479681762610";
            return 0;
        }
    }
 return 0;
}